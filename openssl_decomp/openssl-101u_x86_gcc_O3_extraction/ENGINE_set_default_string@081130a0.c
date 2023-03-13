
int ENGINE_set_default_string(ENGINE *e,char *def_list)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_GS_OFFSET;
  uint local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = 0;
  uVar2 = CONF_parse_list(def_list,0x2c,1,int_def_cb,&local_14);
  uVar1 = local_14;
  if (uVar2 == 0) {
    ERR_put_error(0x26,0xbd,0x96,"eng_fat.c",0x8e);
    ERR_add_error_data(2,&DAT_082232df,def_list);
    goto LAB_08113148;
  }
  if (((((local_14 & 0x40) == 0) || (iVar3 = ENGINE_set_default_ciphers(e), iVar3 != 0)) &&
      (((uVar1 & 0x80) == 0 || (iVar3 = ENGINE_set_default_digests(e), iVar3 != 0)))) &&
     ((((uVar1 & 1) == 0 || (iVar3 = ENGINE_set_default_RSA(e), iVar3 != 0)) &&
      (((uVar1 & 2) == 0 || (iVar3 = ENGINE_set_default_DSA(e), iVar3 != 0)))))) {
    if (((uVar1 & 4) != 0) && (iVar3 = ENGINE_set_default_DH(e), iVar3 == 0)) {
      uVar2 = 0;
      goto LAB_08113148;
    }
    if (((uVar1 & 0x10) != 0) && (iVar3 = ENGINE_set_default_ECDH(e), iVar3 == 0)) {
      uVar2 = 0;
      goto LAB_08113148;
    }
    if (((uVar1 & 0x20) != 0) && (iVar3 = ENGINE_set_default_ECDSA(e), iVar3 == 0)) {
      uVar2 = 0;
      goto LAB_08113148;
    }
    if ((((uVar1 & 8) == 0) || (iVar3 = ENGINE_set_default_RAND(e), iVar3 != 0)) &&
       (((uVar1 & 0x200) == 0 || (iVar3 = ENGINE_set_default_pkey_meths(e), iVar3 != 0)))) {
      uVar2 = 1;
      if ((uVar1 & 0x400) != 0) {
        iVar3 = ENGINE_set_default_pkey_asn1_meths(e);
        uVar2 = (uint)(iVar3 != 0);
      }
      goto LAB_08113148;
    }
  }
  uVar2 = 0;
LAB_08113148:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

