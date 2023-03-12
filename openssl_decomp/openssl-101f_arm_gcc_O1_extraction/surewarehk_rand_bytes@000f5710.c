
void surewarehk_rand_bytes(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  size_t len;
  uint local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined2 local_58;
  undefined auStack_56 [50];
  int local_24;
  
  local_68 = *(uint *)PTR_s_ENGINE_rand_bytes_000f5894;
  uStack_64 = *(undefined4 *)(PTR_s_ENGINE_rand_bytes_000f5894 + 4);
  uStack_60 = *(undefined4 *)(PTR_s_ENGINE_rand_bytes_000f5894 + 8);
  uStack_5c = *(undefined4 *)(PTR_s_ENGINE_rand_bytes_000f5894 + 0xc);
  local_58 = (undefined2)*(undefined4 *)(PTR_s_ENGINE_rand_bytes_000f5894 + 0x10);
  local_24 = __TMC_END__;
  memset(auStack_56,0,0x2e);
  if (p_surewarehk_Rand_Bytes == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6c,0x75,"e_sureware.c",0x26e);
    uVar2 = 0;
  }
  else {
    iVar1 = (*p_surewarehk_Rand_Bytes)(&local_68,param_1,param_2);
    switch(iVar1) {
    case 1:
      uVar2 = 1;
      goto LAB_000f5770;
    case -5:
      ERR_put_error(0x26,0x6c,0x6a,"e_sureware.c",0x254);
      break;
    case -4:
      ERR_put_error(0x26,0x6c,0x67,"e_sureware.c",0x251);
      break;
    case -3:
      ERR_put_error(0x26,0x6c,0x68,"e_sureware.c",0x24b);
      break;
    case -2:
      ERR_put_error(0x26,0x6c,0x66,"e_sureware.c",0x24e);
      break;
    default:
      ERR_put_error(0x26,0x6c,0x65,"e_sureware.c",599);
    }
    if (((local_68 & 0xff) != 0) && (ERR_add_error_data(1,&local_68), logstream != (BIO *)0x0)) {
      CRYPTO_lock(9,0x15,"e_sureware.c",0x261);
      len = strlen((char *)&local_68);
      BIO_write(logstream,&local_68,len);
      CRYPTO_lock(10,0x15,"e_sureware.c",0x263);
    }
    uVar2 = count_leading_zeroes(iVar1 + -1);
    uVar2 = uVar2 >> 5;
  }
LAB_000f5770:
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

