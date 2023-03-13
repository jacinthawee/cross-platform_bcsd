
int BN_num_bits_word(ulong param_1)

{
  if ((param_1 & 0xffff0000) == 0) {
    if ((char)(param_1 >> 8) == '\0') {
      return (uint)(byte)bits_6057[param_1];
    }
    return (byte)bits_6057[param_1 >> 8] + 8;
  }
  if ((param_1 & 0xff000000) != 0) {
    return (byte)bits_6057[param_1 >> 0x18] + 0x18;
  }
  return (byte)bits_6057[param_1 >> 0x10] + 0x10;
}

