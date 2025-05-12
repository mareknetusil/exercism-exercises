module ReverseString (reverseString) where

reverseString :: String -> String
reverseString str = foldl (flip (:)) "" str
