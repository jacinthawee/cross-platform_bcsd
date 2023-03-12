
size_t buffer_ctrl(BIO *param_1,int param_2,size_t param_3,BIO *param_4)

{
  size_t sVar1;
  void *pvVar2;
  long lVar3;
  bio_st *bp;
  char *pcVar4;
  size_t *psVar6;
  void *pvVar7;
  size_t sVar8;
  char *pcVar5;
  
  psVar6 = (size_t *)param_1->ptr;
  if (param_2 == 0xc) {
    lVar3 = BIO_int_ctrl(param_4,0x75,*psVar6,0);
    if (lVar3 == 0) {
      return 0;
    }
    lVar3 = BIO_int_ctrl(param_4,0x75,psVar6[1],1);
    if (lVar3 == 0) {
      return 0;
    }
    return 1;
  }
  if (param_2 < 0xd) {
    if (param_2 == 3) {
      return psVar6[6];
    }
    if (param_2 < 4) {
      if (param_2 == 1) {
        bp = param_1->next_bio;
        psVar6[4] = 0;
        psVar6[3] = 0;
        psVar6[7] = 0;
        psVar6[6] = 0;
        if (bp == (bio_st *)0x0) {
          return 0;
        }
        goto LAB_0009f2e2;
      }
    }
    else {
      if (param_2 == 10) {
        sVar1 = psVar6[3];
        goto joined_r0x0009f2da;
      }
      if (param_2 == 0xb) {
        bp = param_1->next_bio;
        if (bp == (bio_st *)0x0) {
          return 0;
        }
        if (0 < (int)psVar6[6]) {
          while( true ) {
            BIO_clear_flags(param_1,0xf);
            if ((int)psVar6[6] < 1) break;
            sVar1 = BIO_write(param_1->next_bio,(void *)(psVar6[5] + psVar6[7]),psVar6[6]);
            BIO_copy_next_retry(param_1);
            if ((int)sVar1 < 1) {
              return sVar1;
            }
            psVar6[7] = psVar6[7] + sVar1;
            psVar6[6] = psVar6[6] - sVar1;
          }
          bp = param_1->next_bio;
          param_2 = 0xb;
          psVar6[6] = 0;
          psVar6[7] = 0;
        }
        goto LAB_0009f2e2;
      }
    }
LAB_0009f41a:
    bp = param_1->next_bio;
  }
  else {
    if (param_2 == 0x74) {
      if (0 < (int)psVar6[3]) {
        sVar1 = 0;
        pcVar5 = (char *)(psVar6[2] + psVar6[4]);
        do {
          pcVar4 = pcVar5 + 1;
          if (*pcVar5 == '\n') {
            sVar1 = sVar1 + 1;
          }
          pcVar5 = pcVar4;
        } while (pcVar4 != (char *)(psVar6[2] + psVar6[3] + psVar6[4]));
        return sVar1;
      }
      return 0;
    }
    if (0x74 < param_2) {
      if (param_2 == 0x75) {
        sVar1 = param_3;
        sVar8 = param_3;
        if (param_4 != (BIO *)0x0) {
          if (param_4->method == (BIO_METHOD *)0x0) {
            sVar1 = psVar6[1];
          }
          else {
            sVar8 = *psVar6;
          }
        }
        pvVar2 = (void *)psVar6[2];
        pvVar7 = (void *)psVar6[5];
        if ((((int)sVar8 < 0x1001) || (*psVar6 == sVar8)) ||
           (pvVar2 = CRYPTO_malloc(param_3,"bf_buff.c",0x171), pvVar2 != (void *)0x0)) {
          if ((((int)sVar1 < 0x1001) || (psVar6[1] == sVar1)) ||
             (pvVar7 = CRYPTO_malloc(param_3,"bf_buff.c",0x176), pvVar7 != (void *)0x0)) {
            if ((void *)psVar6[2] != pvVar2) {
              CRYPTO_free((void *)psVar6[2]);
              psVar6[2] = (size_t)pvVar2;
              *psVar6 = sVar8;
              psVar6[4] = 0;
              psVar6[3] = 0;
            }
            if ((void *)psVar6[5] != pvVar7) {
              CRYPTO_free((void *)psVar6[5]);
              psVar6[5] = (size_t)pvVar7;
              psVar6[1] = sVar1;
              psVar6[7] = 0;
              psVar6[6] = 0;
              return 1;
            }
            return 1;
          }
          if ((void *)psVar6[2] != pvVar2) {
            CRYPTO_free(pvVar2);
          }
        }
LAB_0009f3ba:
        ERR_put_error(0x20,0x72,0x41,"bf_buff.c",0x1c1);
        return 0;
      }
      if (param_2 == 0x7a) {
        if ((int)*psVar6 < (int)param_3) {
          pvVar2 = CRYPTO_malloc(param_3,"bf_buff.c",0x153);
          if (pvVar2 == (void *)0x0) goto LAB_0009f3ba;
          if ((void *)psVar6[2] != (void *)0x0) {
            CRYPTO_free((void *)psVar6[2]);
          }
          psVar6[2] = (size_t)pvVar2;
        }
        else {
          pvVar2 = (void *)psVar6[2];
        }
        psVar6[3] = param_3;
        psVar6[4] = 0;
        memcpy(pvVar2,param_4,param_3);
        return 1;
      }
      goto LAB_0009f41a;
    }
    if (param_2 != 0xd) {
      if (param_2 == 0x65) {
        if (param_1->next_bio == (bio_st *)0x0) {
          return 0;
        }
        BIO_clear_flags(param_1,0xf);
        sVar1 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
        BIO_copy_next_retry(param_1);
        return sVar1;
      }
      goto LAB_0009f41a;
    }
    sVar1 = psVar6[6];
joined_r0x0009f2da:
    if (sVar1 != 0) {
      return sVar1;
    }
    bp = param_1->next_bio;
  }
  if (bp == (bio_st *)0x0) {
    return 0;
  }
LAB_0009f2e2:
  sVar1 = BIO_ctrl(bp,param_2,param_3,param_4);
  return sVar1;
}

