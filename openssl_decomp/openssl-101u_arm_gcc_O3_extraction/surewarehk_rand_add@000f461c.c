
void surewarehk_rand_add(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  size_t len;
  uint local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined local_58;
  undefined auStack_57 [51];
  int local_24;
  
  local_68 = *(uint *)PTR_s_ENGINE_rand_seed_000f4780;
  uStack_64 = *(undefined4 *)(PTR_s_ENGINE_rand_seed_000f4780 + 4);
  uStack_60 = *(undefined4 *)(PTR_s_ENGINE_rand_seed_000f4780 + 8);
  uStack_5c = *(undefined4 *)(PTR_s_ENGINE_rand_seed_000f4780 + 0xc);
  local_58 = (undefined)*(undefined4 *)(PTR_s_ENGINE_rand_seed_000f4780 + 0x10);
  local_24 = __stack_chk_guard;
  memset(auStack_57,0,0x2f);
  if (p_surewarehk_Rand_Seed == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6d,0x75,"e_sureware.c",0x2a1);
  }
  else {
    uVar1 = (*p_surewarehk_Rand_Seed)(&local_68,param_1,param_2);
    switch(uVar1) {
    case 1:
      goto switchD_000f466a_caseD_1;
    case 0xfffffffb:
      ERR_put_error(0x26,0x6d,0x6a,"e_sureware.c",0x27b);
      break;
    case 0xfffffffc:
      ERR_put_error(0x26,0x6d,0x67,"e_sureware.c",0x278);
      break;
    case 0xfffffffd:
      ERR_put_error(0x26,0x6d,0x68,"e_sureware.c",0x272);
      break;
    case 0xfffffffe:
      ERR_put_error(0x26,0x6d,0x66,"e_sureware.c",0x275);
      break;
    default:
      ERR_put_error(0x26,0x6d,0x65,"e_sureware.c",0x27e);
    }
    if (((local_68 & 0xff) != 0) && (ERR_add_error_data(1,&local_68), logstream != (BIO *)0x0)) {
      CRYPTO_lock(9,0x15,"e_sureware.c",0x286);
      len = strlen((char *)&local_68);
      BIO_write(logstream,&local_68,len);
      CRYPTO_lock(10,0x15,"e_sureware.c",0x288);
    }
  }
switchD_000f466a_caseD_1:
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

