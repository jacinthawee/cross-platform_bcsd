
undefined4 cswift_rand_bytes(undefined4 *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_GS_OFFSET;
  byte bVar6;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 *local_438;
  undefined4 local_434 [5];
  undefined4 local_420 [256];
  int local_20;
  
  bVar6 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_440);
  if (iVar1 == 0) {
    if (0x3ff < (int)param_2) {
      do {
        local_43c = 0x400;
        local_438 = param_1;
        iVar1 = (*p_CSwift_SimpleRequest)(local_440,5,0,0,&local_43c,1);
        if (iVar1 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(CSWIFT_lib_error_code,0x6c,0x6b,"e_cswift.c",0x419);
          puVar3 = local_420;
          goto LAB_0819ef0e;
        }
        param_2 = param_2 - 0x400;
        param_1 = param_1 + 0x100;
      } while (0x3ff < param_2);
    }
    uVar4 = 1;
    if (param_2 != 0) {
      local_438 = local_420;
      local_43c = 0x400;
      iVar1 = (*p_CSwift_SimpleRequest)(local_440,5,0,0,&local_43c,1);
      if (iVar1 == 0) {
        if (param_2 < 4) {
          if ((param_2 != 0) &&
             (*(undefined *)param_1 = *(undefined *)local_438, (param_2 & 2) != 0)) {
            *(undefined2 *)((int)param_1 + (param_2 - 2)) =
                 *(undefined2 *)((int)local_438 + (param_2 - 2));
          }
        }
        else {
          *param_1 = *local_438;
          *(undefined4 *)((int)param_1 + (param_2 - 4)) =
               *(undefined4 *)((int)local_438 + (param_2 - 4));
          iVar1 = (int)param_1 - (int)(undefined4 *)((uint)(param_1 + 1) & 0xfffffffc);
          puVar3 = (undefined4 *)((int)local_438 - iVar1);
          puVar5 = (undefined4 *)((uint)(param_1 + 1) & 0xfffffffc);
          for (uVar2 = param_2 + iVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar5 = *puVar3;
            puVar3 = puVar3 + (uint)bVar6 * -2 + 1;
            puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
          }
        }
        uVar4 = 1;
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CSWIFT_lib_error_code,0x6c,0x6b,"e_cswift.c",0x428);
        puVar3 = local_434;
LAB_0819ef0e:
        uVar4 = 0;
        __sprintf_chk(puVar3,1,0x14,"%ld",iVar1);
        ERR_add_error_data(2,"CryptoSwift error number is ",puVar3);
      }
    }
    (*p_CSwift_ReleaseAccContext)(local_440);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    uVar4 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x6c,0x6c,"e_cswift.c",0x3fc);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

