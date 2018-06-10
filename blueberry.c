void w_byte(int loc, char byte) {
	key_map[loc + 0x80] = byte;
	return;
};

char r_byte(int loc) {
	return key_map[loc + 0x80];
};

int kernel_test() {
	key_map[0xffff] = 0xff;
	if (key_map[0xffff] == 0xff) {
		return 0;
	};
	return 1;
};
