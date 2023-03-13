
int ENGINE_set_default(ENGINE *e,uint flags)

{
  uint uVar1;
  int iVar2;
  
  if (((((((flags & 0x40) == 0) || (iVar2 = ENGINE_set_default_ciphers(e), iVar2 != 0)) &&
        (((flags & 0x80) == 0 || (iVar2 = ENGINE_set_default_digests(e), iVar2 != 0)))) &&
       (((flags & 1) == 0 || (iVar2 = ENGINE_set_default_RSA(e), iVar2 != 0)))) &&
      (((flags & 2) == 0 || (iVar2 = ENGINE_set_default_DSA(e), iVar2 != 0)))) &&
     ((((((flags & 4) == 0 || (iVar2 = ENGINE_set_default_DH(e), iVar2 != 0)) &&
        (((flags & 0x10) == 0 || (iVar2 = ENGINE_set_default_ECDH(e), iVar2 != 0)))) &&
       (((flags & 0x20) == 0 || (iVar2 = ENGINE_set_default_ECDSA(e), iVar2 != 0)))) &&
      ((((flags & 8) == 0 || (iVar2 = ENGINE_set_default_RAND(e), iVar2 != 0)) &&
       (((flags & 0x200) == 0 || (iVar2 = ENGINE_set_default_pkey_meths(e), iVar2 != 0)))))))) {
    uVar1 = 1;
    if ((flags & 0x400) != 0) {
      iVar2 = ENGINE_set_default_pkey_asn1_meths(e);
      uVar1 = (uint)(iVar2 != 0);
    }
    return uVar1;
  }
  return 0;
}

