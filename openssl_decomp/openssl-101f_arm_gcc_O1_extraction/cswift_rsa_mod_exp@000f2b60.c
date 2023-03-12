
void cswift_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  RSA_METHOD *pRVar4;
  void *pvVar5;
  int iVar6;
  size_t sVar7;
  BIGNUM *pBVar8;
  BIGNUM *a;
  BIGNUM *a_00;
  void *pvVar9;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *a_03;
  BIGNUM *a_04;
  undefined4 local_7c;
  int local_78;
  ulong *local_74;
  size_t local_70;
  ulong *local_6c;
  undefined4 local_68;
  uint local_64;
  void *local_60;
  uint local_5c;
  void *local_58;
  uint local_54;
  void *local_50;
  uint local_4c;
  void *local_48;
  uint local_44;
  void *local_40;
  undefined auStack_3c [16];
  int local_2c;
  
  local_2c = __TMC_END__;
  if ((((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
      (param_3->dmp1 == (BIGNUM *)0x0)) ||
     ((param_3->dmq1 == (BIGNUM *)0x0 || (param_3->iqmp == (BIGNUM *)0x0)))) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x6b,0x69,"e_cswift.c",0x2ed);
    pvVar5 = (void *)0x0;
    goto LAB_000f2bea;
  }
  iVar3 = BN_num_bits(param_3->p);
  if ((((0x400 < iVar3) || (iVar3 = BN_num_bits(param_3->q), 0x400 < iVar3)) ||
      ((iVar3 = BN_num_bits(param_3->dmp1), 0x400 < iVar3 ||
       ((iVar3 = BN_num_bits(param_3->dmq1), 0x400 < iVar3 ||
        (iVar3 = BN_num_bits(param_3->iqmp), 0x400 < iVar3)))))) &&
     (pRVar4 = RSA_PKCS1_SSLeay(), pRVar4 != (RSA_METHOD *)0x0)) {
    pvVar5 = (void *)(*pRVar4->rsa_mod_exp)(param_1,param_2,param_3,param_4);
    goto LAB_000f2bea;
  }
  local_60 = (void *)0x0;
  local_58 = (void *)0x0;
  local_50 = (void *)0x0;
  local_48 = (void *)0x0;
  local_40 = (void *)0x0;
  pBVar8 = param_3->dmp1;
  a_03 = param_3->p;
  a = param_3->dmq1;
  a_04 = param_3->q;
  a_00 = param_3->iqmp;
  iVar3 = (*p_CSwift_AcquireAccContext)(&local_7c);
  if (iVar3 == 0) {
    a_01 = BN_new();
    a_02 = BN_new();
    if (a_02 != (BIGNUM *)0x0 && a_01 != (BIGNUM *)0x0) {
      local_68 = 1;
      iVar6 = BN_num_bits(a_03);
      iVar3 = iVar6 + 0xe;
      if (-1 < iVar6 + 7) {
        iVar3 = iVar6 + 7;
      }
      local_64 = iVar3 >> 3;
      sVar7 = local_64 & 0x1f;
      sVar2 = (uint)(a_02 == (BIGNUM *)0x0 || a_01 == (BIGNUM *)0x0);
      uVar1 = sVar7;
      while (uVar1 != 0) {
        local_64 = local_64 + 1;
        sVar7 = sVar2 + 1;
        sVar2 = sVar7;
        uVar1 = local_64 & 0x1f;
      }
      local_60 = CRYPTO_malloc(local_64,"e_cswift.c",0x252);
      if (local_60 == (void *)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x28d;
      }
      else {
        BN_bn2bin(a_03,(uchar *)((int)local_60 + sVar7));
        if (sVar7 != 0) {
          memset(local_60,0,sVar7);
        }
        iVar6 = BN_num_bits(a_04);
        iVar3 = iVar6 + 0xe;
        if (-1 < iVar6 + 7) {
          iVar3 = iVar6 + 7;
        }
        local_5c = iVar3 >> 3;
        sVar7 = local_5c & 0x1f;
        if (sVar7 != 0) {
          sVar7 = 0;
          do {
            local_5c = local_5c + 1;
            sVar7 = sVar7 + 1;
          } while ((local_5c & 0x1f) != 0);
        }
        local_58 = CRYPTO_malloc(local_5c,"e_cswift.c",0x252);
        if (local_58 == (void *)0x0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          iVar3 = 0x292;
        }
        else {
          BN_bn2bin(a_04,(uchar *)((int)local_58 + sVar7));
          if (sVar7 != 0) {
            memset(local_58,0,sVar7);
          }
          iVar6 = BN_num_bits(pBVar8);
          iVar3 = iVar6 + 0xe;
          if (-1 < iVar6 + 7) {
            iVar3 = iVar6 + 7;
          }
          local_54 = iVar3 >> 3;
          sVar7 = local_54 & 0x1f;
          if (sVar7 != 0) {
            sVar7 = 0;
            do {
              local_54 = local_54 + 1;
              sVar7 = sVar7 + 1;
            } while ((local_54 & 0x1f) != 0);
          }
          local_50 = CRYPTO_malloc(local_54,"e_cswift.c",0x252);
          if (local_50 == (void *)0x0) {
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = ERR_get_next_error_library();
            }
            iVar3 = 0x297;
          }
          else {
            BN_bn2bin(pBVar8,(uchar *)((int)local_50 + sVar7));
            if (sVar7 != 0) {
              memset(local_50,0,sVar7);
            }
            iVar6 = BN_num_bits(a);
            iVar3 = iVar6 + 0xe;
            if (-1 < iVar6 + 7) {
              iVar3 = iVar6 + 7;
            }
            local_4c = iVar3 >> 3;
            sVar7 = local_4c & 0x1f;
            if (sVar7 != 0) {
              sVar7 = 0;
              do {
                local_4c = local_4c + 1;
                sVar7 = sVar7 + 1;
              } while ((local_4c & 0x1f) != 0);
            }
            local_48 = CRYPTO_malloc(local_4c,"e_cswift.c",0x252);
            if (local_48 != (void *)0x0) {
              BN_bn2bin(a,(uchar *)((int)local_48 + sVar7));
              if (sVar7 != 0) {
                memset(local_48,0,sVar7);
              }
              iVar6 = BN_num_bits(a_00);
              iVar3 = iVar6 + 0xe;
              if (-1 < iVar6 + 7) {
                iVar3 = iVar6 + 7;
              }
              local_44 = iVar3 >> 3;
              sVar7 = local_44 & 0x1f;
              if (sVar7 != 0) {
                sVar7 = 0;
                do {
                  local_44 = local_44 + 1;
                  sVar7 = sVar7 + 1;
                } while ((local_44 & 0x1f) != 0);
              }
              pvVar5 = CRYPTO_malloc(local_44,"e_cswift.c",0x252);
              local_40 = pvVar5;
              if (pvVar5 == (void *)0x0) {
                pvVar9 = (void *)0x1;
                ERR_CSWIFT_error_constprop_3(0x6a,0x67,0x2a1);
              }
              else {
                BN_bn2bin(a_00,(uchar *)((int)pvVar5 + sVar7));
                if (sVar7 != 0) {
                  memset(local_40,0,sVar7);
                }
                if (((a_01->dmax < param_2->top) &&
                    (pBVar8 = bn_expand2(a_01,param_2->top), pBVar8 == (BIGNUM *)0x0)) ||
                   ((iVar3 = a_04->top + a_03->top, a_02->dmax < iVar3 &&
                    (pBVar8 = bn_expand2(a_02,iVar3), pBVar8 == (BIGNUM *)0x0)))) {
                  pvVar9 = (void *)0x1;
                  ERR_CSWIFT_error_constprop_3(0x6a,0x67,0x2a7);
                  pvVar5 = (void *)0x0;
                }
                else {
                  iVar3 = (*p_CSwift_AttachKeyParam)(local_7c,&local_68);
                  if (iVar3 == -0x2716) {
                    pvVar9 = (void *)0x1;
                    ERR_CSWIFT_error_constprop_3(0x6a,0x65,0x2b2);
                    pvVar5 = (void *)0x0;
                  }
                  else {
                    if (iVar3 == 0) {
                      local_78 = BN_bn2bin(param_2,(uchar *)a_01->d);
                      local_74 = a_01->d;
                      iVar3 = BN_num_bits(a_03);
                      pvVar9 = (void *)0x1;
                      iVar6 = iVar3 + 7;
                      if (iVar6 < 0) {
                        iVar6 = iVar3 + 0xe;
                      }
                      local_70 = (iVar6 >> 3) << 1;
                      memset(a_02->d,0,local_70);
                      local_6c = a_02->d;
                      iVar3 = (*p_CSwift_SimpleRequest)(local_7c,1,&local_78,1,&local_70,1);
                      if (iVar3 == 0) {
                        BN_bin2bn((uchar *)a_02->d,local_70,param_1);
                        pvVar5 = pvVar9;
                        goto LAB_000f2c8c;
                      }
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2c8);
                    }
                    else {
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2b7);
                    }
                    pvVar9 = (void *)0x1;
                    __sprintf_chk(auStack_3c,1,0xd,&DAT_001695a8,iVar3);
                    ERR_add_error_data(2,"CryptoSwift error number is ",auStack_3c);
                    pvVar5 = (void *)0x0;
                  }
                }
              }
              goto LAB_000f2c8c;
            }
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = ERR_get_next_error_library();
            }
            iVar3 = 0x29c;
          }
        }
      }
      pvVar9 = (void *)0x1;
      ERR_put_error(CSWIFT_lib_error_code,0x6a,0x67,"e_cswift.c",iVar3);
      pvVar5 = (void *)0x0;
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      pvVar9 = (void *)0x1;
      ERR_put_error(CSWIFT_lib_error_code,0x6a,0x66,"e_cswift.c",0x280);
      pvVar5 = (void *)0x0;
    }
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x6a,0x6c,"e_cswift.c",0x276);
    pvVar9 = (void *)0x0;
    a_01 = (BIGNUM *)0x0;
    a_02 = (BIGNUM *)0x0;
    pvVar5 = (void *)0x0;
  }
LAB_000f2c8c:
  if (local_60 != (void *)0x0) {
    CRYPTO_free(local_60);
  }
  if (local_58 != (void *)0x0) {
    CRYPTO_free(local_58);
  }
  if (local_50 != (void *)0x0) {
    CRYPTO_free(local_50);
  }
  if (local_48 != (void *)0x0) {
    CRYPTO_free(local_48);
  }
  if (local_40 != (void *)0x0) {
    CRYPTO_free(local_40);
  }
  if (a_02 != (BIGNUM *)0x0) {
    BN_free(a_02);
  }
  if (a_01 != (BIGNUM *)0x0) {
    BN_free(a_01);
  }
  if (pvVar9 != (void *)0x0) {
    (*p_CSwift_ReleaseAccContext)(local_7c);
  }
LAB_000f2bea:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pvVar5);
}

