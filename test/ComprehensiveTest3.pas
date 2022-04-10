program hello;
const
	a = -1;
type
	ary = array[-1..1] of integer;
var
	ar: array [-1..1] of integer;
	b : ary;
	ans : integer;

function gcd(a, b : integer) : integer;
const
	c = -1;
type
	ary = array[-1..1] of integer;
var
	ar: array [-1..1] of integer;
	e : ary;
begin
	if b = 0 then begin
		gcd := a;
	end
	else begin
		gcd := gcd(b , a mod b);
	end
	;
end
;

begin
	ans := gcd(9 , 36) * gcd(3 , 6);
	writeln(ans);
end
.