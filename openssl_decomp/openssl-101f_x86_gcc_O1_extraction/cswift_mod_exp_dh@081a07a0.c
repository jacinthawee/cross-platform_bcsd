
undefined4
cswift_mod_exp_dh(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5
                 ,BN_CTX *param_6)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar2;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  int in_GS_OFFSET;
  undefined4 local_70;
  int local_6c;
  ulong *local_68;
  size_t local_64;
  ulong *local_60;
  undefined4 local_5c;
  int local_58;
  ulong *local_54;
  int local_50;
  ulong *local_4c;
  undefined local_2d [13];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_70);
  if (iVar1 != 0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    uVar4 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,0x6c,"e_cswift.c",0x1fe);
    goto LAB_081a0823;
  }
  BN_CTX_start(param_6);
  a = BN_CTX_get(param_6);
  a_00 = BN_CTX_get(param_6);
  a_01 = BN_CTX_get(param_6);
  a_02 = BN_CTX_get(param_6);
  if (a_02 == (BIGNUM *)0x0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x20a;
    iVar1 = 0x66;
LAB_081a0a54:
    uVar4 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,iVar1,"e_cswift.c",iVar2);
  }
  else {
    if (a->dmax < param_5->top) {
      pBVar3 = bn_expand2(a,param_5->top);
      if (pBVar3 != (BIGNUM *)0x0) {
        iVar1 = param_4->top;
        if (a_00->dmax < iVar1) goto LAB_081a0aa5;
        goto LAB_081a08ac;
      }
LAB_081a0a10:
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x210;
      iVar1 = 0x67;
      goto LAB_081a0a54;
    }
    iVar1 = param_4->top;
    if (a_00->dmax < iVar1) {
LAB_081a0aa5:
      pBVar3 = bn_expand2(a_00,iVar1);
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_081a0a10;
    }
LAB_081a08ac:
    if (((a_01->dmax < param_3->top) &&
        (pBVar3 = bn_expand2(a_01,param_3->top), pBVar3 == (BIGNUM *)0x0)) ||
       ((a_02->dmax < param_5->top &&
        (pBVar3 = bn_expand2(a_02,param_5->top), pBVar3 == (BIGNUM *)0x0)))) goto LAB_081a0a10;
    local_5c = 2;
    local_58 = BN_bn2bin(param_5,(uchar *)a->d);
    local_54 = a->d;
    local_50 = BN_bn2bin(param_4,(uchar *)a_00->d);
    local_4c = a_00->d;
    iVar1 = (*p_CSwift_AttachKeyParam)(local_70,&local_5c);
    if (iVar1 == -0x2716) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x221;
      iVar1 = 0x65;
      goto LAB_081a0a54;
    }
    if (iVar1 == 0) {
      local_6c = BN_bn2bin(param_3,(uchar *)a_01->d);
      local_68 = a_01->d;
      iVar2 = BN_num_bits(param_5);
      iVar1 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar1 = iVar2 + 0xe;
      }
      local_64 = iVar1 >> 3;
      memset(a_02->d,0,local_64);
      local_60 = a_02->d;
      iVar1 = (*p_CSwift_SimpleRequest)(local_70,2,&local_6c,1,&local_64,1);
      if (iVar1 != 0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x237);
        goto LAB_081a0b08;
      }
      uVar4 = 1;
      BN_bin2bn((uchar *)a_02->d,local_64,param_2);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x226);
LAB_081a0b08:
      __sprintf_chk(local_2d,1,0xd,"%ld",iVar1);
      uVar4 = 0;
      ERR_add_error_data(2,"CryptoSwift error number is ",local_2d);
    }
  }
  (*p_CSwift_ReleaseAccContext)(local_70);
LAB_081a0823:
  BN_CTX_end(param_6);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

