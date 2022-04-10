program mytest;
const
    t = -1;
type
    ar = integer;
var
    a : array [t..t] of ar;
begin

    a[-1] := 1;
end.