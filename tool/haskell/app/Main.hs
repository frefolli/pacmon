{-# LANGUAGE OverloadedStrings #-}
module Main where

import HaskellSay (haskellSay)
import Lib.Source.Index as SourceIndex
import Data.Text (append)

join _ [] = ""
join _ [x] = x
join sep (x:y:xs) = append x $ append sep $ join sep (y:xs)

f = do
    let plist = SourceIndex.packages <$> SourceIndex.parseFromFile "../source/index.yml" in
        join " " <$> plist

main :: IO ()
main = do
    file <- f
    haskellSay $ show file
