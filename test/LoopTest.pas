program LoopTest;
var 
    i : integer;

begin
    for i := 1 to 3 do
    begin
        writeln(i);
    end;

    while i> 0 do 
    begin 
        writeln(i);
        i := i - 1;
    end;

	repeat
		i := i + 1;
		writeln(i);
	until i = 3;
end
.
