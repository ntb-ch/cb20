-- cb20_gpio_block_0.vhd

-- Generated using ACDS version 13.0sp1 232 at 2016.09.14.15:59:33

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity cb20_gpio_block_0 is
	generic (
		number_of_gpios : integer                       := 9;
		unique_id       : std_logic_vector(31 downto 0) := "00010010011100000101000000000001"
	);
	port (
		oslv_avs_read_data  : out   std_logic_vector(31 downto 0);                    -- avalon_slave_0.readdata
		islv_avs_address    : in    std_logic_vector(3 downto 0)  := (others => '0'); --               .address
		isl_avs_read        : in    std_logic                     := '0';             --               .read
		isl_avs_write       : in    std_logic                     := '0';             --               .write
		osl_avs_waitrequest : out   std_logic;                                        --               .waitrequest
		islv_avs_write_data : in    std_logic_vector(31 downto 0) := (others => '0'); --               .writedata
		islv_avs_byteenable : in    std_logic_vector(3 downto 0)  := (others => '0'); --               .byteenable
		isl_clk             : in    std_logic                     := '0';             --     clock_sink.clk
		isl_reset_n         : in    std_logic                     := '0';             --     reset_sink.reset_n
		oslv_gpios          : inout std_logic_vector(8 downto 0)  := (others => '0')  --    conduit_end.export
	);
end entity cb20_gpio_block_0;

architecture rtl of cb20_gpio_block_0 is
	component avalon_gpio_interface is
		generic (
			number_of_gpios : integer                       := 1;
			unique_id       : std_logic_vector(31 downto 0) := "00000000000000000000000000000000"
		);
		port (
			oslv_avs_read_data  : out   std_logic_vector(31 downto 0);                    -- readdata
			islv_avs_address    : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- address
			isl_avs_read        : in    std_logic                     := 'X';             -- read
			isl_avs_write       : in    std_logic                     := 'X';             -- write
			osl_avs_waitrequest : out   std_logic;                                        -- waitrequest
			islv_avs_write_data : in    std_logic_vector(31 downto 0) := (others => 'X'); -- writedata
			islv_avs_byteenable : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- byteenable
			isl_clk             : in    std_logic                     := 'X';             -- clk
			isl_reset_n         : in    std_logic                     := 'X';             -- reset_n
			oslv_gpios          : inout std_logic_vector(8 downto 0)  := (others => 'X')  -- export
		);
	end component avalon_gpio_interface;

begin

	number_of_gpios_check : if number_of_gpios /= 9 generate
		assert false report "Supplied generics do not match expected generics" severity Failure;
	end generate;

	unique_id_check : if unique_id /= "00010010011100000101000000000001" generate
		assert false report "Supplied generics do not match expected generics" severity Failure;
	end generate;

	gpio_block_0 : component avalon_gpio_interface
		generic map (
			number_of_gpios => 9,
			unique_id       => "00010010011100000101000000000001"
		)
		port map (
			oslv_avs_read_data  => oslv_avs_read_data,  -- avalon_slave_0.readdata
			islv_avs_address    => islv_avs_address,    --               .address
			isl_avs_read        => isl_avs_read,        --               .read
			isl_avs_write       => isl_avs_write,       --               .write
			osl_avs_waitrequest => osl_avs_waitrequest, --               .waitrequest
			islv_avs_write_data => islv_avs_write_data, --               .writedata
			islv_avs_byteenable => islv_avs_byteenable, --               .byteenable
			isl_clk             => isl_clk,             --     clock_sink.clk
			isl_reset_n         => isl_reset_n,         --     reset_sink.reset_n
			oslv_gpios          => oslv_gpios           --    conduit_end.export
		);

end architecture rtl; -- of cb20_gpio_block_0
