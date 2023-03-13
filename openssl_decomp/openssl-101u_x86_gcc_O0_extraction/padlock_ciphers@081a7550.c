
undefined4
padlock_ciphers(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  if (param_2 != (undefined4 *)0x0) {
    switch(param_4) {
    case 0x1a2:
      *param_2 = padlock_aes_128_ecb;
      return 1;
    case 0x1a3:
      *param_2 = padlock_aes_128_cbc;
      return 1;
    case 0x1a4:
      *param_2 = padlock_aes_128_ofb;
      return 1;
    case 0x1a5:
      *param_2 = padlock_aes_128_cfb;
      return 1;
    case 0x1a6:
      *param_2 = padlock_aes_192_ecb;
      return 1;
    case 0x1a7:
      *param_2 = padlock_aes_192_cbc;
      return 1;
    case 0x1a8:
      *param_2 = padlock_aes_192_ofb;
      return 1;
    case 0x1a9:
      *param_2 = padlock_aes_192_cfb;
      return 1;
    case 0x1aa:
      *param_2 = padlock_aes_256_ecb;
      return 1;
    case 0x1ab:
      *param_2 = padlock_aes_256_cbc;
      return 1;
    case 0x1ac:
      *param_2 = padlock_aes_256_ofb;
      return 1;
    case 0x1ad:
      *param_2 = padlock_aes_256_cfb;
      return 1;
    default:
      *param_2 = 0;
      return 0;
    }
  }
  *param_3 = padlock_cipher_nids;
  return 0xc;
}

