program typetest;
const
	l = -1;
	r = 1;
type
	inte = integer;
	inte2 = inte;
	ar = array[l..r] of inte2;
	re = record
			ra : integer;
			rb : boolean;
			rc : char;
			rd : real;
		end;

var 
	arr : ar;
	rec : re;
begin
	arr[l] := l;
	arr[0] := 0;
	arr[r] := r;
	writeln(arr[l]);
	writeln(arr[0]);
	writeln(arr[r]);
	rec.ra := 1;
	rec.rb := false;
	rec.rc := 'a';
	rec.rd := 1.1;
	writeln(rec.ra);
	writeln(1);
	writeln(rec.rc);
	writeln(rec.rd);
end.
