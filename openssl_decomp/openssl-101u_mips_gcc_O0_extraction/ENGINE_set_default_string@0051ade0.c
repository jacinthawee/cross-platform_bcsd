
int ENGINE_set_default_string(ENGINE *e,char *def_list)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ENGINE *e_00;
  uint local_18;
  ENGINE *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_18 = 0;
  local_14 = *(ENGINE **)PTR___stack_chk_guard_006a9ae8;
  uVar3 = (*(code *)PTR_CONF_parse_list_006a87f8)(def_list,0x2c,1,int_def_cb,&local_18);
  uVar2 = local_18;
  if (uVar3 == 0) {
    ERR_put_error(0x26,0xbd,0x96,"eng_fat.c",0x8e);
    ERR_add_error_data(2,&DAT_006670f0,def_list);
  }
  else {
    if ((local_18 & 0x40) != 0) {
      iVar4 = ENGINE_set_default_ciphers(e);
      if (iVar4 == 0) {
        uVar3 = 0;
        goto LAB_0051af18;
      }
    }
    if ((uVar2 & 0x80) != 0) {
      iVar4 = ENGINE_set_default_digests(e);
      if (iVar4 == 0) {
        uVar3 = 0;
        goto LAB_0051af18;
      }
    }
    if ((uVar2 & 1) != 0) {
      iVar4 = ENGINE_set_default_RSA(e);
      if (iVar4 == 0) {
        uVar3 = 0;
        goto LAB_0051af18;
      }
    }
    if ((uVar2 & 2) != 0) {
      iVar4 = ENGINE_set_default_DSA(e);
      if (iVar4 == 0) {
        uVar3 = 0;
        goto LAB_0051af18;
      }
    }
    if ((uVar2 & 4) != 0) {
      iVar4 = ENGINE_set_default_DH(e);
      if (iVar4 == 0) {
        uVar3 = 0;
        goto LAB_0051af18;
      }
    }
    if ((uVar2 & 0x10) != 0) {
      iVar4 = ENGINE_set_default_ECDH(e);
      if (iVar4 == 0) {
        uVar3 = 0;
        goto LAB_0051af18;
      }
    }
    if ((uVar2 & 0x20) != 0) {
      iVar4 = ENGINE_set_default_ECDSA(e);
      if (iVar4 == 0) {
        uVar3 = 0;
        goto LAB_0051af18;
      }
    }
    if ((uVar2 & 8) != 0) {
      iVar4 = ENGINE_set_default_RAND(e);
      if (iVar4 == 0) {
        uVar3 = 0;
        goto LAB_0051af18;
      }
    }
    if ((uVar2 & 0x200) != 0) {
      iVar4 = ENGINE_set_default_pkey_meths(e);
      if (iVar4 == 0) {
        uVar3 = 0;
        goto LAB_0051af18;
      }
    }
    if ((uVar2 & 0x400) == 0) {
      uVar3 = 1;
    }
    else {
      iVar4 = ENGINE_set_default_pkey_asn1_meths(e);
      uVar3 = (uint)(iVar4 != 0);
    }
  }
LAB_0051af18:
  if (local_14 == *(ENGINE **)puVar1) {
    return uVar3;
  }
  e_00 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ENGINE_register_ciphers(e_00);
  ENGINE_register_digests(e_00);
  ENGINE_register_RSA(e_00);
  ENGINE_register_DSA(e_00);
  ENGINE_register_DH(e_00);
  ENGINE_register_ECDH(e_00);
  ENGINE_register_ECDSA(e_00);
  ENGINE_register_RAND(e_00);
  ENGINE_register_pkey_meths(e_00);
  return 1;
}

