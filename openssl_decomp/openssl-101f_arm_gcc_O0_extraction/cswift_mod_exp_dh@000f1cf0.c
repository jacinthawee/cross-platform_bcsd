
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void cswift_mod_exp_dh(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                      BIGNUM *param_5,BN_CTX *param_6)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar2;
  BIGNUM *pBVar3;
  undefined4 uVar4;
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
  
  local_2c = __TMC_END__;
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_7c);
  if (iVar1 != 0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    uVar4 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,0x6c,"e_cswift.c",0x1fe);
    goto LAB_000f1d42;
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
    uVar4 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,0x66,"e_cswift.c",0x20a);
    goto LAB_000f1f26;
  }
  if (a->dmax < param_5->top) {
    pBVar3 = bn_expand2(a,param_5->top);
    if (pBVar3 != (BIGNUM *)0x0) {
      iVar1 = param_4->top;
      if (a_00->dmax < iVar1) goto LAB_000f1f52;
      goto LAB_000f1da0;
    }
LAB_000f1eda:
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    uVar4 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,0x67,"e_cswift.c",0x210);
  }
  else {
    iVar1 = param_4->top;
    if (a_00->dmax < iVar1) {
LAB_000f1f52:
      pBVar3 = bn_expand2(a_00,iVar1);
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_000f1eda;
    }
LAB_000f1da0:
    if (((a_01->dmax < param_3->top) &&
        (pBVar3 = bn_expand2(a_01,param_3->top), pBVar3 == (BIGNUM *)0x0)) ||
       ((a_02->dmax < param_5->top &&
        (pBVar3 = bn_expand2(a_02,param_5->top), pBVar3 == (BIGNUM *)0x0)))) goto LAB_000f1eda;
    local_68 = 2;
    local_64 = BN_bn2bin(param_5,(uchar *)a->d);
    local_60 = a->d;
    local_5c = BN_bn2bin(param_4,(uchar *)a_00->d);
    local_58 = a_00->d;
    iVar1 = (*p_CSwift_AttachKeyParam)(local_7c,&local_68);
    if (iVar1 == -0x2716) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      uVar4 = 0;
      ERR_put_error(CSWIFT_lib_error_code,0x69,0x65,"e_cswift.c",0x221);
    }
    else {
      if (iVar1 == 0) {
        uVar4 = 1;
        local_78 = BN_bn2bin(param_3,(uchar *)a_01->d);
        local_74 = a_01->d;
        iVar2 = BN_num_bits(param_5);
        iVar1 = iVar2 + 0xe;
        if (-1 < iVar2 + 7) {
          iVar1 = iVar2 + 7;
        }
        local_70 = iVar1 >> 3;
        memset(a_02->d,0,local_70);
        local_6c = a_02->d;
        iVar1 = (*p_CSwift_SimpleRequest)(local_7c,2,&local_78,1,&local_70,1);
        if (iVar1 == 0) {
          BN_bin2bn((uchar *)a_02->d,local_70,param_2);
          goto LAB_000f1f26;
        }
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x237);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x226);
      }
      __sprintf_chk(auStack_3c,1,0xd,&DAT_001695cc,iVar1);
      uVar4 = 0;
      ERR_add_error_data(2,"CryptoSwift error number is ",auStack_3c);
    }
  }
LAB_000f1f26:
  (*p_CSwift_ReleaseAccContext)(local_7c);
LAB_000f1d42:
  BN_CTX_end(param_6);
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}

