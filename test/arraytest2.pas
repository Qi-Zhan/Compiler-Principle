program arraytest2;
const
	a = -1;
type
	ary = array[-1..1] of integer;
var
	ar: array [-1..1] of integer;
	b : ary;

begin
	ar[a] := 1;
	b[-1] := 2;
	writeln(ar[-1], ' ', b[a]);
end
.
