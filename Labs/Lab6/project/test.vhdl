library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity memory is
	port
	(
		clk			: in  std_logic;
		rst			: in  std_logic;
		memread			: in  std_logic;
		memwrite		: in  std_logic;
		address1		: in  std_logic_vector (31 downto 0);
		address2		: in  std_logic_vector (31 downto 0);
		writedata		: in  std_logic_vector (31 downto 0);
		instruction		: out std_logic_vector (31 downto 0);
		readdata		: out std_logic_vector (31 downto 0)
	);
end memory;

architecture behavior of memory is
	type ramcell is array (0 to 255) of std_logic_vector (7 downto 0);
	signal ram			: ramcell;
	signal masked1, masked2		: std_logic_vector (7 downto 0);
	signal selector1, selector2	: natural range 0 to 255;
begin
	masked1 <= address1 (7 downto 2) & "00";
	masked2 <= address2 (7 downto 2) & "00";
	selector1 <= to_integer (unsigned (masked1));
	selector2 <= to_integer (unsigned (masked2));

	process (clk, rst, memread, memwrite, address1, address2, writedata)
	begin
		if (rising_edge (clk)) then
			if (rst = '1') then
				ram (  0) <= "00000011"; -- ori $s0,$0,3
				ram (  1) <= "00000000";
				ram (  2) <= "00010000";
				ram (  3) <= "00110100";
				ram (  4) <= "11111110"; -- ori $s1,$0,-2
				ram (  5) <= "11111111";
				ram (  6) <= "00010001";
				ram (  7) <= "00110100";
				ram (  8) <= "10100100"; -- ori $s2,$0,420
				ram (  9) <= "00000001";
				ram ( 10) <= "00010010";
				ram ( 11) <= "00110100";
				ram ( 12) <= "10111011"; -- ori $s3,$0,-69
				ram ( 13) <= "11111111";
				ram ( 14) <= "00010011";
				ram ( 15) <= "00110100";
				ram ( 16) <= "00100111"; -- nor $s4,$0,$0
				ram ( 17) <= "10100000";
				ram ( 18) <= "00000000";
				ram ( 19) <= "00000000";
				ram ( 20) <= "00010100"; -- ori $t0,$0,20
				ram ( 21) <= "00000000";
				ram ( 22) <= "00001000";
				ram ( 23) <= "00110100";
				ram ( 24) <= "00010101"; -- ori $t1,$0,21
				ram ( 25) <= "00000000";
				ram ( 26) <= "00001001";
				ram ( 27) <= "00110100";
				ram ( 28) <= "00010110"; -- ori $t2,$0,22
				ram ( 29) <= "00000000";
				ram ( 30) <= "00001010";
				ram ( 31) <= "00110100";
				ram ( 32) <= "00000010"; -- ori $t3,$0,2
				ram ( 33) <= "00000000";
				ram ( 34) <= "00001011";
				ram ( 35) <= "00110100";
				ram ( 36) <= "00001001"; -- jalr $ra,$t0
				ram ( 37) <= "11111000";
				ram ( 38) <= "00000000";
				ram ( 39) <= "00000001";
				ram ( 40) <= "00001001"; -- jalr $ra,$t1
				ram ( 41) <= "11111000";
				ram ( 42) <= "00100000";
				ram ( 43) <= "00000001";
				ram ( 44) <= "00001001"; -- jalr $ra,$t2
				ram ( 45) <= "11111000";
				ram ( 46) <= "01000000";
				ram ( 47) <= "00000001";
				ram ( 48) <= "00001001"; -- jalr $ra,$t3
				ram ( 49) <= "11111000";
				ram ( 50) <= "01100000";
				ram ( 51) <= "00000001";
				for i in 52 to 255 loop
					ram (i) <= std_logic_vector (to_unsigned (0, 8));
				end loop;
			else
				if (memwrite = '1') then
					ram (selector2 + 0) <= writedata (7 downto 0);
					ram (selector2 + 1) <= writedata (15 downto 8);
					ram (selector2 + 2) <= writedata (23 downto 16);
					ram (selector2 + 3) <= writedata (31 downto 24);
				end if;
			end if;
		end if;
	end process;
	instruction <= ram (selector1 + 3) & ram (selector1 + 2) & ram (selector1 + 1) & ram (selector1 + 0);
	with memread select
		readdata <=	std_logic_vector (to_unsigned (0, 32)) when '0',
				ram (selector2 + 3) & ram (selector2 + 2) & ram (selector2 + 1) & ram (selector2 + 0) when others;
end behavior;
