{-# LANGUAGE DeriveGeneric, OverloadedStrings, RecordWildCards #-}

module Lib.Source.Index where

import Data.Text (Text)
import Data.ByteString (ByteString)
import qualified Data.Yaml as Yaml
import GHC.Generics

data Index = Index {
    platforms :: [Text]
} deriving (Generic, Show, Eq)

instance Yaml.ToJSON Index
instance Yaml.FromJSON Index

-- constructor

new platforms = (Index platforms)
newEmpty _ = new []

-- manipulation

appendPlatform :: Text -> Index -> Maybe Index
appendPlatform platform (Index platforms) =
    if not (hasPlatform (Index platforms) platform) then
        Just $ Index (platform : platforms)
    else
        Nothing


removePlatform :: Text -> Index -> Maybe Index
removePlatform platform (Index platforms) =
    if (hasPlatform (Index platforms) platform) then
        Just $ Index $ filter (\x -> platform /= x) platforms
    else
        Nothing

renamePlatform :: Text -> Text -> Index -> Maybe Index
renamePlatform platform newname (Index platforms) =
    if (hasPlatform (Index platforms) platform) && not (hasPlatform (Index platforms) newname) then
        Just $ Index $ (newname : filter (\x -> platform /= x) platforms)
    else
        Nothing

hasPlatform :: Index -> Text -> Bool
hasPlatform (Index []) platform = False
hasPlatform (Index (x : xs)) platform = (x == platform) || (hasPlatform (Index xs) platform)

-- parse and dump

parseFromString :: ByteString -> Index
parseFromString bytestring = 
    let result = Yaml.decodeEither' bytestring
    in either newEmpty id result

parseFromFile :: FilePath -> IO Index
parseFromFile filepath =
    let result = Yaml.decodeFileEither filepath
    in either newEmpty id <$> result

dumpToString :: Index -> ByteString
dumpToString index = Yaml.encode index

dumpToFile :: FilePath -> Index -> IO()
dumpToFile filepath index = Yaml.encodeFile filepath index
