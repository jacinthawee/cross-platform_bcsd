
int app_info_LHASH_HASH(CRYPTO_THREADID *param_1)

{
  ulong uVar1;
  
  uVar1 = CRYPTO_THREADID_hash(param_1);
  return uVar1 * 0x45bb + (uVar1 >> 0xe) * 7 + (uVar1 >> 4) * 0xfb;
}
