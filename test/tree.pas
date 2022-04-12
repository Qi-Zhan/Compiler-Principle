program tree;
var
	a:array[0..39] of integer;
	b,p:array[0..1599] of integer;
	n,i:integer;
	
function tree(l,r:integer):integer;
var
	k,i:integer;
begin
	if b[l*40+r]=0 then
	begin
		if l>r then
			begin
				b[l*40+r]:=1;p[l*40+r]:=0;
			end
		else
			if l=r then
				begin
					b[l*40+r]:=a[l];
					p[l*40+r]:=l;
				end
			else
				begin
					for i:=l to r do
						begin
							k:=tree(l,i-1)*tree(i+1,r)+a[i];
							if k>b[l*40+r] then
								begin
									b[l*40+r]:=k;
									p[l*40+r]:=i;
								end;
						end;
				end;
	end;
	tree:=b[l*40+r];
end;

procedure dfs(l,r:integer);
begin
	if p[l*40+r]>0 then
	begin
		write(p[l*40+r],' ');
		dfs(l,p[l*40+r]-1);
		dfs(p[l*40+r]+1,r);
	end;
end;

begin
	read(n);
	for i:=1 to n do
		read(a[i]);
	writeln(tree(1,n));
	dfs(1,n);
end.

