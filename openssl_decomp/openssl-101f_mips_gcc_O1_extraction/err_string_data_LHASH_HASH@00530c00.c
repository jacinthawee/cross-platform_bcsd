
uint err_string_data_LHASH_HASH(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  uVar1 = uVar1 >> 0x18 ^ uVar1 ^ (uVar1 << 8) >> 0x14;
  return (uVar1 - ((uVar1 / 0x13) * 3 +
                  ((uint)((ulonglong)uVar1 * 0x1af286bcb >> 0x21) & 0xfffffff0))) * 0xd ^ uVar1;
}
