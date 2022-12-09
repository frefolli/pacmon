{-# LANGUAGE DeriveGeneric, OverloadedStrings, RecordWildCards #-}

module Lib.Source.Index where

import Data.Text (Text)
import Data.ByteString (ByteString)
import qualified Data.Yaml as Yaml
import GHC.Generics

data Index = Index {
    packages :: [Text]
} deriving (Generic, Show, Eq)

instance Yaml.ToJSON Index
instance Yaml.FromJSON Index

new packages = (Index packages)

parseFromString :: ByteString -> Index
parseFromString bytestring = 
    let result = Yaml.decodeEither' bytestring
    in either (\_ -> new []) id result

parseFromFile :: FilePath -> IO Index
parseFromFile filepath =
    let result = Yaml.decodeFileEither filepath
    in either (\_ -> new []) id <$> result

dumpToString :: Index -> ByteString
dumpToString index = Yaml.encode index

dumpToFile :: Index -> FilePath -> IO()
dumpToFile index filepath = Yaml.encodeFile filepath index
