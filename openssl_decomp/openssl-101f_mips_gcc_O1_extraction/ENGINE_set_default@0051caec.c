
int ENGINE_set_default(ENGINE *e,uint flags)

{
  int iVar1;
  
  if (((((((flags & 0x40) == 0) || (iVar1 = ENGINE_set_default_ciphers(e), iVar1 != 0)) &&
        (((flags & 0x80) == 0 || (iVar1 = ENGINE_set_default_digests(e), iVar1 != 0)))) &&
       (((flags & 1) == 0 || (iVar1 = ENGINE_set_default_RSA(e), iVar1 != 0)))) &&
      (((flags & 2) == 0 || (iVar1 = ENGINE_set_default_DSA(e), iVar1 != 0)))) &&
     ((((((flags & 4) == 0 || (iVar1 = ENGINE_set_default_DH(e), iVar1 != 0)) &&
        (((flags & 0x10) == 0 || (iVar1 = ENGINE_set_default_ECDH(e), iVar1 != 0)))) &&
       (((flags & 0x20) == 0 || (iVar1 = ENGINE_set_default_ECDSA(e), iVar1 != 0)))) &&
      ((((flags & 8) == 0 || (iVar1 = ENGINE_set_default_RAND(e), iVar1 != 0)) &&
       (((flags & 0x200) == 0 || (iVar1 = ENGINE_set_default_pkey_meths(e), iVar1 != 0)))))))) {
    if ((flags & 0x400) != 0) {
      iVar1 = ENGINE_set_default_pkey_asn1_meths(e);
      return (uint)(iVar1 != 0);
    }
    return 1;
  }
  return 0;
}

