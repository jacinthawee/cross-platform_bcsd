
undefined4 surewarehk_load_pubkey(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_GS_OFFSET;
  char local_55;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [11];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_54 = 0;
  local_55 = '\0';
  puVar3 = local_3c;
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_50 = 0x49474e45;
  local_4c = 0x6c5f454e;
  local_48 = 0x5f64616f;
  local_44 = 0x6b627570;
  local_40 = 0x7965;
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
    uVar1 = 0;
  }
  else {
    iVar2 = (*p_surewarehk_Info_Pubkey)(&local_50,param_2,&local_54,&local_55);
    if (iVar2 == 1) {
      uVar1 = sureware_load_public(local_54,(int)local_55);
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      ERR_add_error_data(1,&local_50);
      uVar1 = 0;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

