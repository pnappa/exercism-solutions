module Bob

// TODO: fix to ignore trailing whitespace
let isQ (sval: string): bool = 
    match String.length (sval.Trim()) with
     | 0 -> false
     | _ -> sval.Trim() |> Seq.last = '?'

let isExclaim (sval: string): bool = 
    let hasSpoke = String.exists (fun c -> System.Char.IsLetter c) sval
    let allCaps = String.forall (fun c -> System.Char.IsUpper c || not (System.Char.IsLetter c)) sval
    match (hasSpoke, allCaps) with
     | (true, true) -> true
     | _ -> false

// return true if only contains whitespace, otherwise false
let exclusivelyWhitespace (sval: string): bool = 
    sval |> Seq.fold (fun accum item -> accum && System.Char.IsWhiteSpace item) true

let response (input: string): string = 
    match (isQ input, isExclaim input, exclusivelyWhitespace input) with
     | (true, false, false) -> "Sure."
     | (true, true, false) -> "Calm down, I know what I'm doing!"
     | (false, true, false) -> "Whoa, chill out!"
     | (_, _, true) -> "Fine. Be that way!"
     | _ -> "Whatever."
