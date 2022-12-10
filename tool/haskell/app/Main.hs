{-# LANGUAGE OverloadedStrings #-}
module Main where

import HaskellSay (haskellSay)
import Lib.Source.Index as Source.Index
import Data.Maybe (fromJust, isJust, Maybe(..))

main :: IO ()
main =
    let rep = Source.Index.dumpToString $ Source.Index.new ["bash", "bash-config"] in
    let obj = Source.Index.parseFromString rep in do
    a <- Just obj >>= Source.Index.appendPlatform "vim" >>= Source.Index.appendPlatform "vim-config"
    b <- a >>= Source.Index.appendPlatform "emacs" >>= Source.Index.appendPlatform "emacs2" >>= Source.Index.renamePlatform "emacs2" "emacs-config"
    c <- b >>= Source.Index.appendPlatform "emacs2" >>= Source.Index.removePlatform "emacs2"
    d <- c >>= Source.Index.dumpToFile "file.yml"
    if isJust d then
        fromJust d
    else
        error "cannot operate"
