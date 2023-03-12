
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void cswift_mod_exp_mont(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                        BN_CTX *param_5,BN_MONT_CTX *param_6)

{
  int iVar1;
  RSA_METHOD *pRVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  undefined4 local_7c;
  int local_78;
  ulong *local_74;
  size_t local_70;
  ulong *local_6c;
  undefined4 local_68;
  int local_64;
  ulong *local_60;
  int local_5c;
  ulong *local_58;
  undefined auStack_3c [16];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar1 = BN_num_bits(param_1);
  if ((((0x800 < iVar1) || (iVar1 = BN_num_bits(param_2), 0x800 < iVar1)) ||
      (iVar1 = BN_num_bits(param_4), 0x800 < iVar1)) &&
     (pRVar2 = RSA_PKCS1_SSLeay(), pRVar2 != (RSA_METHOD *)0x0)) {
    iVar1 = (*pRVar2->bn_mod_exp)(param_1,param_2,param_3,param_4,param_5,param_6);
    goto LAB_000f0210;
  }
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_7c);
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
      iVar1 = 0;
      ERR_put_error(CSWIFT_lib_error_code,0x69,0x66,"e_cswift.c",0x20a);
    }
    else if (((((a->dmax < param_4->top) &&
               (pBVar5 = bn_expand2(a,param_4->top), pBVar5 == (BIGNUM *)0x0)) ||
              ((a_00->dmax < param_3->top &&
               (pBVar5 = bn_expand2(a_00,param_3->top), pBVar5 == (BIGNUM *)0x0)))) ||
             ((a_01->dmax < param_2->top &&
              (pBVar5 = bn_expand2(a_01,param_2->top), pBVar5 == (BIGNUM *)0x0)))) ||
            ((a_02->dmax < param_4->top &&
             (pBVar5 = bn_expand2(a_02,param_4->top), pBVar5 == (BIGNUM *)0x0)))) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      iVar1 = 0;
      ERR_put_error(CSWIFT_lib_error_code,0x69,0x67,"e_cswift.c",0x20f);
    }
    else {
      local_68 = 2;
      local_64 = BN_bn2bin(param_4,(uchar *)a->d);
      local_60 = a->d;
      local_5c = BN_bn2bin(param_3,(uchar *)a_00->d);
      local_58 = a_00->d;
      iVar3 = (*p_CSwift_AttachKeyParam)(local_7c,&local_68);
      if (iVar3 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar1 = 0;
        ERR_put_error(CSWIFT_lib_error_code,0x69,0x65,"e_cswift.c",0x21f);
      }
      else {
        if (iVar3 == 0) {
          iVar1 = 1;
          local_78 = BN_bn2bin(param_2,(uchar *)a_01->d);
          local_74 = a_01->d;
          iVar4 = BN_num_bits(param_4);
          iVar3 = iVar4 + 0xe;
          if (-1 < iVar4 + 7) {
            iVar3 = iVar4 + 7;
          }
          local_70 = iVar3 >> 3;
          memset(a_02->d,0,local_70);
          local_6c = a_02->d;
          iVar3 = (*p_CSwift_SimpleRequest)(local_7c,2,&local_78,1,&local_70,1);
          if (iVar3 == 0) {
            BN_bin2bn((uchar *)a_02->d,local_70,param_1);
            goto LAB_000f03d8;
          }
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x234);
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x224);
        }
        __sprintf_chk(auStack_3c,1,0xd,&DAT_00168298,iVar3);
        iVar1 = 0;
        ERR_add_error_data(2,"CryptoSwift error number is ",auStack_3c);
      }
    }
LAB_000f03d8:
    (*p_CSwift_ReleaseAccContext)(local_7c);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    iVar1 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,0x6c,"e_cswift.c",0x1ff);
  }
  BN_CTX_end(param_5);
LAB_000f0210:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}

