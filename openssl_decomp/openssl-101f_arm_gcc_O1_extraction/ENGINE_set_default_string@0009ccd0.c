
int ENGINE_set_default_string(ENGINE *e,char *def_list)

{
  int iVar1;
  int iVar2;
  int local_14;
  
  local_14 = 0;
  iVar1 = CONF_parse_list(def_list,0x2c,1,int_def_cb + 1,&local_14);
  iVar2 = local_14;
  if (iVar1 == 0) {
    ERR_put_error(0x26,0xbd,0x96,"eng_fat.c",0x8f);
    ERR_add_error_data(2,&DAT_0015ec3c,def_list);
    return 0;
  }
  if ((((((-1 < local_14 << 0x19) || (iVar1 = ENGINE_set_default_ciphers(e), iVar1 != 0)) &&
        ((-1 < iVar2 << 0x18 || (iVar1 = ENGINE_set_default_digests(e), iVar1 != 0)))) &&
       ((-1 < iVar2 << 0x1f || (iVar1 = ENGINE_set_default_RSA(e), iVar1 != 0)))) &&
      ((-1 < iVar2 << 0x1e || (iVar1 = ENGINE_set_default_DSA(e), iVar1 != 0)))) &&
     (((((-1 < iVar2 << 0x1d || (iVar1 = ENGINE_set_default_DH(e), iVar1 != 0)) &&
        ((-1 < iVar2 << 0x1b || (iVar1 = ENGINE_set_default_ECDH(e), iVar1 != 0)))) &&
       ((-1 < iVar2 << 0x1a || (iVar1 = ENGINE_set_default_ECDSA(e), iVar1 != 0)))) &&
      (((-1 < iVar2 << 0x1c || (iVar1 = ENGINE_set_default_RAND(e), iVar1 != 0)) &&
       ((-1 < iVar2 << 0x16 || (iVar1 = ENGINE_set_default_pkey_meths(e), iVar1 != 0)))))))) {
    if (iVar2 << 0x15 < 0) {
      iVar2 = ENGINE_set_default_pkey_asn1_meths(e);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
    }
    else {
      iVar2 = 1;
    }
    return iVar2;
  }
  return 0;
}

