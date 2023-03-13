
int cswift_mod_exp_mont(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                       BN_CTX *param_5,BN_MONT_CTX *param_6)

{
  int iVar1;
  RSA_METHOD *pRVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar3;
  BIGNUM *pBVar4;
  int in_GS_OFFSET;
  int line;
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
  iVar1 = BN_num_bits(param_1);
  if ((((0x800 < iVar1) || (iVar1 = BN_num_bits(param_2), 0x800 < iVar1)) ||
      (iVar1 = BN_num_bits(param_4), 0x800 < iVar1)) &&
     (pRVar2 = RSA_PKCS1_SSLeay(), pRVar2 != (RSA_METHOD *)0x0)) {
    iVar1 = (*pRVar2->bn_mod_exp)(param_1,param_2,param_3,param_4,param_5,param_6);
    goto LAB_0819f6ec;
  }
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_70);
  if (iVar1 == 0) {
    BN_CTX_start(param_5);
    a = BN_CTX_get(param_5);
    a_00 = BN_CTX_get(param_5);
    a_01 = BN_CTX_get(param_5);
    a_02 = BN_CTX_get(param_5);
    if (a_02 == (BIGNUM *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x20a;
      iVar3 = 0x66;
LAB_0819f977:
      iVar1 = 0;
      ERR_put_error(CSWIFT_lib_error_code,0x69,iVar3,"e_cswift.c",line);
    }
    else {
      if (((((a->dmax < param_4->top) &&
            (pBVar4 = bn_expand2(a,param_4->top), pBVar4 == (BIGNUM *)0x0)) ||
           ((a_00->dmax < param_3->top &&
            (pBVar4 = bn_expand2(a_00,param_3->top), pBVar4 == (BIGNUM *)0x0)))) ||
          ((a_01->dmax < param_2->top &&
           (pBVar4 = bn_expand2(a_01,param_2->top), pBVar4 == (BIGNUM *)0x0)))) ||
         ((a_02->dmax < param_4->top &&
          (pBVar4 = bn_expand2(a_02,param_4->top), pBVar4 == (BIGNUM *)0x0)))) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        line = 0x20f;
        iVar3 = 0x67;
        goto LAB_0819f977;
      }
      local_5c = 2;
      local_58 = BN_bn2bin(param_4,(uchar *)a->d);
      local_54 = a->d;
      local_50 = BN_bn2bin(param_3,(uchar *)a_00->d);
      local_4c = a_00->d;
      iVar1 = (*p_CSwift_AttachKeyParam)(local_70,&local_5c);
      if (iVar1 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        line = 0x21f;
        iVar3 = 0x65;
        goto LAB_0819f977;
      }
      if (iVar1 == 0) {
        local_6c = BN_bn2bin(param_2,(uchar *)a_01->d);
        local_68 = a_01->d;
        iVar3 = BN_num_bits(param_4);
        iVar1 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar1 = iVar3 + 0xe;
        }
        local_64 = iVar1 >> 3;
        memset(a_02->d,0,local_64);
        local_60 = a_02->d;
        iVar1 = (*p_CSwift_SimpleRequest)(local_70,2,&local_6c,1,&local_64,1);
        if (iVar1 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x234);
          goto LAB_0819f9ee;
        }
        iVar1 = 1;
        BN_bin2bn((uchar *)a_02->d,local_64,param_1);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x224);
LAB_0819f9ee:
        __sprintf_chk(local_2d,1,0xd,"%ld",iVar1);
        iVar1 = 0;
        ERR_add_error_data(2,"CryptoSwift error number is ",local_2d);
      }
    }
    (*p_CSwift_ReleaseAccContext)(local_70);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    iVar1 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,0x6c,"e_cswift.c",0x1ff);
  }
  BN_CTX_end(param_5);
LAB_0819f6ec:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

