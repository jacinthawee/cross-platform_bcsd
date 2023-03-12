
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ENGINE_register_all_complete(void)

{
  ENGINE *e;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    if (((byte)e[0x54] & 8) == 0) {
      ENGINE_register_ciphers(e);
      ENGINE_register_digests(e);
      ENGINE_register_RSA(e);
      ENGINE_register_DSA(e);
      ENGINE_register_DH(e);
      ENGINE_register_ECDH(e);
      ENGINE_register_ECDSA(e);
      ENGINE_register_RAND(e);
      e = (ENGINE *)ENGINE_register_pkey_meths(e);
    }
  }
  return 1;
}

