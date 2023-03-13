
/* WARNING: Could not reconcile some variable overlaps */

void surewarehk_rand_add(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int in_GS_OFFSET;
  bool bVar8;
  uint local_50 [4];
  undefined4 local_40;
  undefined4 local_3c [11];
  int local_10;
  
  local_50[0] = 0x49474e45;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_50[1] = 0x725f454e;
  local_50[2] = 0x5f646e61;
  puVar7 = local_3c;
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_50[3] = 0x64656573;
  local_40 = 0;
  if (p_surewarehk_Rand_Seed == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6d,0x75,"e_sureware.c",0x2a1);
  }
  else {
    uVar1 = (*p_surewarehk_Rand_Seed)(local_50,param_1,param_2);
    switch(uVar1) {
    case 1:
      goto switchD_081a3b1b_caseD_1;
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
    if (((char)local_50[0] != '\0') && (ERR_add_error_data(1,local_50), logstream != (BIO *)0x0)) {
      CRYPTO_lock((int)logstream,9,(char *)0x15,(int)"e_sureware.c");
      puVar6 = local_50;
      do {
        puVar5 = puVar6;
        uVar2 = *puVar5 + 0xfefefeff & ~*puVar5;
        uVar3 = uVar2 & 0x80808080;
        puVar6 = puVar5 + 1;
      } while (uVar3 == 0);
      bVar8 = (uVar2 & 0x8080) == 0;
      if (bVar8) {
        uVar3 = uVar3 >> 0x10;
      }
      if (bVar8) {
        puVar6 = (uint *)((int)puVar5 + 6);
      }
      iVar4 = BIO_write(logstream,local_50,
                        (int)puVar6 + ((-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3)) - (int)local_50)
                       );
      CRYPTO_lock(iVar4,10,(char *)0x15,(int)"e_sureware.c");
    }
  }
switchD_081a3b1b_caseD_1:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

