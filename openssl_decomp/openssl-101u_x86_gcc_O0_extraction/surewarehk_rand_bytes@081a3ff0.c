
/* WARNING: Could not reconcile some variable overlaps */

bool surewarehk_rand_bytes(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int mode;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int in_GS_OFFSET;
  bool bVar7;
  uint local_50 [4];
  undefined4 local_40;
  undefined4 local_3c [11];
  int local_10;
  
  local_50[0] = 0x49474e45;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_50[1] = 0x725f454e;
  local_50[2] = 0x5f646e61;
  puVar6 = local_3c;
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_50[3] = 0x65747962;
  local_40 = 0x73;
  if (p_surewarehk_Rand_Bytes == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6c,0x75,"e_sureware.c",0x293);
    bVar7 = false;
    goto LAB_081a4070;
  }
  iVar3 = (*p_surewarehk_Rand_Bytes)(local_50,param_1,param_2);
  switch(iVar3) {
  case 1:
    bVar7 = true;
    goto LAB_081a4070;
  case -5:
    ERR_put_error(0x26,0x6c,0x6a,"e_sureware.c",0x27b);
    break;
  case -4:
    ERR_put_error(0x26,0x6c,0x67,"e_sureware.c",0x278);
    goto joined_r0x081a40df;
  case -3:
    ERR_put_error(0x26,0x6c,0x68,"e_sureware.c",0x272);
    break;
  case -2:
    ERR_put_error(0x26,0x6c,0x66,"e_sureware.c",0x275);
    break;
  default:
    ERR_put_error(0x26,0x6c,0x65,"e_sureware.c",0x27e);
  }
joined_r0x081a40df:
  if (((char)local_50[0] != '\0') && (ERR_add_error_data(1,local_50), logstream != (BIO *)0x0)) {
    CRYPTO_lock((int)logstream,9,(char *)0x15,(int)"e_sureware.c");
    puVar5 = local_50;
    do {
      puVar4 = puVar5;
      uVar1 = *puVar4 + 0xfefefeff & ~*puVar4;
      uVar2 = uVar1 & 0x80808080;
      puVar5 = puVar4 + 1;
    } while (uVar2 == 0);
    bVar7 = (uVar1 & 0x8080) == 0;
    if (bVar7) {
      uVar2 = uVar2 >> 0x10;
    }
    if (bVar7) {
      puVar5 = (uint *)((int)puVar4 + 6);
    }
    mode = BIO_write(logstream,local_50,
                     (int)puVar5 + ((-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2)) - (int)local_50));
    CRYPTO_lock(mode,10,(char *)0x15,(int)"e_sureware.c");
  }
  bVar7 = iVar3 == 1;
LAB_081a4070:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar7;
}

