
undefined4 dsa_sign_setup(int param_1,BN_CTX *param_2,BIGNUM **param_3,BIGNUM **param_4)

{
  uint uVar1;
  code *pcVar2;
  BIGNUM *r;
  int iVar3;
  BIGNUM *pBVar4;
  int iVar5;
  BN_MONT_CTX *pBVar6;
  undefined4 uVar7;
  int in_GS_OFFSET;
  BN_CTX *local_5c;
  BIGNUM local_48;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
     (*(int *)(param_1 + 0x14) == 0)) {
    ERR_put_error(10,0x6b,0x65,"dsa_ossl.c",0xe6);
    uVar7 = 0;
    goto LAB_0810e61e;
  }
  BN_init(&local_48);
  BN_init(&local_34);
  local_5c = param_2;
  if (((param_2 == (BN_CTX *)0x0) && (local_5c = BN_CTX_new(), local_5c == (BN_CTX *)0x0)) ||
     (r = BN_new(), r == (BIGNUM *)0x0)) {
    uVar7 = 0;
    ERR_put_error(10,0x6b,3,"dsa_ossl.c",0x135);
  }
  else {
    do {
      iVar3 = BN_rand_range(&local_48,*(BIGNUM **)(param_1 + 0x10));
      if (iVar3 == 0) goto LAB_0810e5d7;
    } while (local_48.top == 0);
    uVar1 = *(uint *)(param_1 + 0x28);
    pBVar4 = &local_48;
    if ((uVar1 & 2) == 0) {
      local_48.flags = local_48.flags | 4;
      if ((uVar1 & 1) == 0) {
LAB_0810e674:
        pBVar4 = BN_copy(&local_34,&local_48);
        if (pBVar4 != (BIGNUM *)0x0) {
          local_34.flags = local_34.flags | 4;
          iVar3 = BN_add(&local_34,&local_34,*(BIGNUM **)(param_1 + 0x10));
          if (iVar3 != 0) {
            iVar3 = BN_num_bits(&local_34);
            iVar5 = BN_num_bits(*(BIGNUM **)(param_1 + 0x10));
            pBVar4 = &local_34;
            if ((iVar5 < iVar3) ||
               (iVar3 = BN_add(&local_34,&local_34,*(BIGNUM **)(param_1 + 0x10)), iVar3 != 0))
            goto LAB_0810e6da;
          }
        }
      }
      else {
LAB_0810e790:
        pBVar6 = BN_MONT_CTX_set_locked
                           ((BN_MONT_CTX **)(param_1 + 0x2c),8,*(BIGNUM **)(param_1 + 0xc),local_5c)
        ;
        if (pBVar6 != (BN_MONT_CTX *)0x0) {
          if ((*(byte *)(param_1 + 0x28) & 2) != 0) goto LAB_0810e6da;
          goto LAB_0810e674;
        }
      }
    }
    else {
      if ((uVar1 & 1) != 0) goto LAB_0810e790;
LAB_0810e6da:
      pcVar2 = *(code **)(*(int *)(param_1 + 0x3c) + 0x14);
      if (pcVar2 == (code *)0x0) {
        iVar3 = BN_mod_exp_mont(r,*(BIGNUM **)(param_1 + 0x14),pBVar4,*(BIGNUM **)(param_1 + 0xc),
                                local_5c,*(BN_MONT_CTX **)(param_1 + 0x2c));
      }
      else {
        iVar3 = (*pcVar2)(param_1,r,*(undefined4 *)(param_1 + 0x14),pBVar4,
                          *(undefined4 *)(param_1 + 0xc),local_5c,*(undefined4 *)(param_1 + 0x2c));
      }
      if (((iVar3 != 0) &&
          (iVar3 = BN_div((BIGNUM *)0x0,r,r,*(BIGNUM **)(param_1 + 0x10),local_5c), iVar3 != 0)) &&
         (pBVar4 = BN_mod_inverse((BIGNUM *)0x0,&local_48,*(BIGNUM **)(param_1 + 0x10),local_5c),
         pBVar4 != (BIGNUM *)0x0)) {
        if (*param_3 != (BIGNUM *)0x0) {
          BN_clear_free(*param_3);
        }
        *param_3 = pBVar4;
        if (*param_4 != (BIGNUM *)0x0) {
          BN_clear_free(*param_4);
        }
        uVar7 = 1;
        *param_4 = r;
        goto LAB_0810e600;
      }
    }
LAB_0810e5d7:
    uVar7 = 0;
    ERR_put_error(10,0x6b,3,"dsa_ossl.c",0x135);
    BN_clear_free(r);
  }
LAB_0810e600:
  if (param_2 == (BN_CTX *)0x0) {
    BN_CTX_free(local_5c);
  }
  BN_clear_free(&local_48);
  BN_clear_free(&local_34);
LAB_0810e61e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}

