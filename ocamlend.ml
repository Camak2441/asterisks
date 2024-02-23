
external forasc : (int -> unit) -> int -> unit = "forasc"
external c_print_char: char -> unit = "c_print_char"

let rec fordesc f = function
  | 0 -> ()
  | n -> f n; fordesc f (n-1)

let set_arg n = forasc (fun x -> fordesc (fun _ -> c_print_char '*') (x + 1); c_print_char '\n') (int_of_string n) 
let speclist = []
let usage_msg = "asterisks <number_of_lines>"

let () = Arg.parse speclist set_arg usage_msg
