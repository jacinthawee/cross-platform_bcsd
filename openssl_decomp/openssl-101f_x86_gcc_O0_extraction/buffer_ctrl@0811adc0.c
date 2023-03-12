
uint buffer_ctrl(bio_st *param_1,int param_2,size_t param_3,BIO *param_4)

{
  char cVar1;
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var2;
  size_t *psVar3;
  long lVar4;
  uint uVar5;
  void *pvVar6;
  void *pvVar7;
  size_t sVar8;
  char *pcVar9;
  size_t sVar10;
  void *local_24;
  
  psVar3 = (size_t *)param_1->ptr;
  if (param_2 == 0xc) {
    lVar4 = BIO_int_ctrl(param_4,0x75,*psVar3,0);
    if (lVar4 == 0) {
      return 0;
    }
    lVar4 = BIO_int_ctrl(param_4,0x75,psVar3[1],1);
    return (uint)(lVar4 != 0);
  }
  if (param_2 < 0xd) {
    if (param_2 == 3) {
      return psVar3[6];
    }
    if (param_2 < 4) {
      if (param_2 == 1) {
        param_1 = param_1->next_bio;
        psVar3[4] = 0;
        psVar3[3] = 0;
        psVar3[7] = 0;
        psVar3[6] = 0;
        if (param_1 == (bio_st *)0x0) {
          return 0;
        }
        param_2 = 1;
        goto code_r0x08117ac0;
      }
    }
    else {
      if (param_2 == 10) {
        if (psVar3[3] != 0) {
          return psVar3[3];
        }
        param_1 = param_1->next_bio;
        if (param_1 == (bio_st *)0x0) {
          return 0;
        }
        param_2 = 10;
        goto code_r0x08117ac0;
      }
      if (param_2 == 0xb) {
        if (param_1->next_bio == (bio_st *)0x0) {
          return 0;
        }
        if ((int)psVar3[6] < 1) {
          param_2 = 0xb;
          param_1 = param_1->next_bio;
        }
        else {
          while( true ) {
            BIO_clear_flags(param_1,0xf);
            if ((int)psVar3[6] < 1) break;
            uVar5 = BIO_write(param_1->next_bio,(void *)(psVar3[7] + psVar3[5]),psVar3[6]);
            BIO_copy_next_retry(param_1);
            if ((int)uVar5 < 1) {
              return uVar5;
            }
            psVar3[7] = psVar3[7] + uVar5;
            psVar3[6] = psVar3[6] - uVar5;
          }
          psVar3[6] = 0;
          psVar3[7] = 0;
          param_2 = 0xb;
          param_1 = param_1->next_bio;
        }
        goto code_r0x08117ac0;
      }
    }
  }
  else {
    if (param_2 == 0x74) {
      if ((int)psVar3[3] < 1) {
        return 0;
      }
      pcVar9 = (char *)(psVar3[2] + psVar3[4]);
      uVar5 = 0;
      do {
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        uVar5 = uVar5 + (cVar1 == '\n');
      } while (pcVar9 != (char *)(psVar3[2] + psVar3[4] + psVar3[3]));
      return uVar5;
    }
    if (param_2 < 0x75) {
      if (param_2 == 0xd) {
        if (psVar3[6] != 0) {
          return psVar3[6];
        }
        if (param_1->next_bio == (bio_st *)0x0) {
          return 0;
        }
        param_2 = 0xd;
        param_1 = param_1->next_bio;
        goto code_r0x08117ac0;
      }
      if (param_2 == 0x65) {
        if (param_1->next_bio != (bio_st *)0x0) {
          BIO_clear_flags(param_1,0xf);
          uVar5 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
          BIO_copy_next_retry(param_1);
          return uVar5;
        }
        return 0;
      }
    }
    else {
      if (param_2 == 0x75) {
        sVar8 = param_3;
        sVar10 = param_3;
        if (param_4 != (BIO *)0x0) {
          if (param_4->method == (BIO_METHOD *)0x0) {
            sVar10 = psVar3[1];
          }
          else {
            sVar8 = *psVar3;
          }
        }
        pvVar6 = (void *)psVar3[5];
        pvVar7 = pvVar6;
        if (((int)sVar8 < 0x1001) || (sVar8 == *psVar3)) {
          if ((int)sVar10 < 0x1001) {
            return 1;
          }
          local_24 = (void *)psVar3[2];
          if (sVar10 == psVar3[1]) goto LAB_0811b050;
LAB_0811b121:
          pvVar7 = CRYPTO_malloc(param_3,"bf_buff.c",0x168);
          if (pvVar7 == (void *)0x0) {
            if ((void *)psVar3[2] != local_24) {
              CRYPTO_free(local_24);
            }
LAB_0811b160:
            ERR_put_error(0x20,0x72,0x41,"bf_buff.c",0x1b6);
            return 0;
          }
        }
        else {
          local_24 = CRYPTO_malloc(param_3,"bf_buff.c",0x163);
          if (local_24 == (void *)0x0) goto LAB_0811b160;
          if ((0x1000 < (int)sVar10) && (sVar10 != psVar3[1])) goto LAB_0811b121;
        }
        if ((void *)psVar3[2] == local_24) {
          pvVar6 = (void *)psVar3[5];
        }
        else {
          CRYPTO_free((void *)psVar3[2]);
          psVar3[4] = 0;
          psVar3[3] = 0;
          psVar3[2] = (size_t)local_24;
          pvVar6 = (void *)psVar3[5];
          *psVar3 = sVar8;
        }
LAB_0811b050:
        if (pvVar6 != pvVar7) {
          CRYPTO_free(pvVar6);
          psVar3[5] = (size_t)pvVar7;
          psVar3[7] = 0;
          psVar3[6] = 0;
          psVar3[1] = sVar10;
        }
        return 1;
      }
      if (param_2 == 0x7a) {
        if ((int)*psVar3 < (int)param_3) {
          pvVar6 = CRYPTO_malloc(param_3,"bf_buff.c",0x141);
          if (pvVar6 == (void *)0x0) goto LAB_0811b160;
          if ((void *)psVar3[2] != (void *)0x0) {
            CRYPTO_free((void *)psVar3[2]);
          }
          psVar3[2] = (size_t)pvVar6;
        }
        else {
          pvVar6 = (void *)psVar3[2];
        }
        psVar3[4] = 0;
        psVar3[3] = param_3;
        memcpy(pvVar6,param_4,param_3);
        return 1;
      }
    }
  }
  param_1 = param_1->next_bio;
  if (param_1 == (bio_st *)0x0) {
    return 0;
  }
code_r0x08117ac0:
  if (param_1 == (bio_st *)0x0) {
    return 0;
  }
  if ((param_1->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = param_1->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    uVar5 = 0xfffffffe;
  }
  else {
    p_Var2 = param_1->callback;
    if (p_Var2 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08117b57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
      return uVar5;
    }
    uVar5 = (*p_Var2)(param_1,6,(char *)param_4,param_2,param_3,1);
    if (0 < (int)uVar5) {
      lVar4 = (*param_1->method->ctrl)(param_1,param_2,param_3,param_4);
      uVar5 = (*p_Var2)(param_1,0x86,(char *)param_4,param_2,param_3,lVar4);
    }
  }
  return uVar5;
}

