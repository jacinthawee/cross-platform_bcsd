
undefined4 x509_main(int param_1,byte **param_2)

{
  byte bVar1;
  X509_STORE *pXVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  X509_STORE **ppXVar7;
  int iVar8;
  BIO_METHOD *pBVar9;
  long lVar10;
  X509_STORE_CTX *pXVar11;
  int iVar12;
  X509_STORE_CTX *pXVar13;
  time_t tVar14;
  undefined4 uVar15;
  uint uVar16;
  EVP_PKEY *to;
  X509_NAME *pXVar17;
  X509_STORE_CTX *pXVar18;
  ASN1_OBJECT *pAVar19;
  X509_PURPOSE *xp;
  int iVar20;
  size_t sVar21;
  BIGNUM *pBVar22;
  ASN1_TIME *pAVar23;
  ASN1_INTEGER *ai;
  int extraout_ECX;
  X509_STORE_CTX *extraout_ECX_00;
  X509_STORE_CTX *extraout_ECX_01;
  X509_STORE_CTX *extraout_ECX_02;
  X509_STORE_CTX *extraout_ECX_03;
  X509_STORE_CTX *extraout_ECX_04;
  X509_STORE_CTX *extraout_ECX_05;
  X509_STORE_CTX *extraout_ECX_06;
  X509_STORE_CTX *extraout_ECX_07;
  X509_STORE_CTX *extraout_ECX_08;
  X509_STORE_CTX *extraout_ECX_09;
  X509_STORE_CTX *extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 extraout_ECX_14;
  undefined4 extraout_ECX_15;
  undefined4 extraout_ECX_16;
  X509_STORE_CTX *extraout_ECX_17;
  X509_STORE_CTX *extraout_ECX_18;
  X509_STORE_CTX *extraout_ECX_19;
  X509_STORE_CTX *extraout_ECX_20;
  X509_STORE_CTX *extraout_ECX_21;
  X509_STORE_CTX *extraout_ECX_22;
  X509_STORE_CTX *extraout_ECX_23;
  X509_STORE_CTX *extraout_ECX_24;
  undefined4 extraout_ECX_25;
  X509_STORE_CTX *extraout_ECX_26;
  X509_STORE_CTX *extraout_ECX_27;
  X509_STORE_CTX *extraout_ECX_28;
  X509_STORE_CTX *extraout_ECX_29;
  X509_STORE_CTX *extraout_ECX_30;
  X509_STORE_CTX *extraout_ECX_31;
  X509_STORE_CTX *extraout_ECX_32;
  X509_STORE_CTX *extraout_ECX_33;
  X509_STORE_CTX *extraout_ECX_34;
  X509_STORE_CTX *extraout_ECX_35;
  uint uVar24;
  undefined4 extraout_ECX_36;
  X509_STORE_CTX *extraout_ECX_37;
  X509_STORE_CTX *extraout_ECX_38;
  X509_STORE_CTX *extraout_ECX_39;
  X509_STORE_CTX *extraout_ECX_40;
  X509_STORE_CTX *extraout_ECX_41;
  X509_STORE_CTX *extraout_ECX_42;
  X509_STORE_CTX *extraout_ECX_43;
  undefined4 extraout_ECX_44;
  X509_STORE_CTX *extraout_ECX_45;
  X509_STORE_CTX *extraout_ECX_46;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  X509_STORE_CTX *extraout_EDX_05;
  X509_STORE_CTX *x;
  undefined1 *puVar25;
  uint uVar26;
  byte *unaff_EBP;
  char *pcVar27;
  X509_STORE_CTX *pXVar28;
  byte **ppbVar29;
  byte *pbVar30;
  undefined4 uVar31;
  byte *pbVar32;
  int in_GS_OFFSET;
  bool bVar33;
  byte bVar34;
  char *pcVar35;
  X509_STORE_CTX *pXVar36;
  X509_STORE_CTX *pXVar37;
  X509_STORE *local_308;
  EVP_PKEY *local_304;
  X509_STORE_CTX *local_300;
  X509_STORE_CTX *local_2fc;
  X509_STORE_CTX *local_2f8;
  _STACK *local_2f4;
  X509_STORE_CTX *local_2f0;
  X509_STORE_CTX *local_2ec;
  _STACK *local_2e8;
  X509_STORE_CTX *local_2e4;
  X509_STORE_CTX *local_2e0;
  int local_2d8;
  X509_STORE_CTX *local_2d4;
  undefined4 local_2d0;
  X509_STORE_CTX *local_2cc;
  undefined4 local_2c8;
  byte *local_2c4;
  X509_STORE_CTX *local_2c0;
  X509_STORE_CTX *local_2bc;
  X509_STORE_CTX *local_2b8;
  X509_STORE_CTX *local_2b4;
  X509_STORE_CTX *local_2ac;
  X509_STORE_CTX *local_2a8;
  byte *local_2a4;
  X509_STORE_CTX *local_2a0;
  byte *local_29c;
  X509_STORE_CTX *local_298;
  X509_STORE_CTX *local_294;
  byte *local_28c;
  X509_STORE_CTX *local_288;
  X509_STORE_CTX *local_284;
  X509_STORE_CTX *local_280;
  X509_STORE_CTX *local_27c;
  X509_STORE_CTX *local_278;
  X509_STORE_CTX *local_274;
  X509_STORE_CTX *local_270;
  X509_STORE_CTX *local_26c;
  X509_STORE_CTX *local_268;
  X509_STORE_CTX *local_264;
  X509_STORE_CTX *local_260;
  X509_STORE_CTX *local_25c;
  X509_STORE_CTX *local_258;
  X509_STORE_CTX *local_254;
  X509_STORE_CTX *local_250;
  X509_STORE_CTX *local_24c;
  X509_STORE_CTX *local_248;
  X509_STORE_CTX *local_244;
  X509_STORE_CTX *local_240;
  X509_STORE_CTX *local_23c;
  X509_STORE_CTX *local_238;
  X509_STORE_CTX *local_234;
  X509_STORE_CTX *local_230;
  X509_STORE_CTX *local_22c;
  long local_224;
  void *local_210;
  X509_STORE_CTX *local_20c;
  ulong local_208;
  X509V3_CTX local_204;
  X509_STORE_CTX local_1e8;
  byte local_160 [64];
  char local_120 [256];
  int local_20;
  
  bVar34 = 0;
  reqfile = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_210 = (void *)0x0;
  local_20c = (X509_STORE_CTX *)0x0;
  local_208 = 0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar8 = load_config(bio_err,0);
  if (iVar8 == 0) {
    local_308 = (X509_STORE *)0x0;
    local_2e0 = (X509_STORE_CTX *)0x0;
  }
  else {
    local_2e0 = (X509_STORE_CTX *)BIO_new_fp(stdout,0);
    local_308 = X509_STORE_new();
    if (local_308 != (X509_STORE *)0x0) {
      X509_STORE_set_verify_cb(local_308,callb);
      param_1 = param_1 + -1;
      local_28c = (byte *)0x0;
      local_224 = 0;
      bVar4 = false;
      bVar3 = false;
      bVar33 = param_1 == 0;
      local_2ec = (X509_STORE_CTX *)0x0;
      local_2f8 = (X509_STORE_CTX *)0x0;
      local_2c4 = (byte *)0x0;
      if (param_1 < 1) {
        local_22c = (X509_STORE_CTX *)0x0;
        local_264 = (X509_STORE_CTX *)0x0;
        local_230 = (X509_STORE_CTX *)0x0;
        local_234 = (X509_STORE_CTX *)0x0;
        local_2ac = (X509_STORE_CTX *)0x1e;
        local_268 = (X509_STORE_CTX *)0x0;
        local_238 = (X509_STORE_CTX *)0x0;
        bVar5 = false;
        local_23c = (X509_STORE_CTX *)0x0;
        local_240 = (X509_STORE_CTX *)0x0;
        local_244 = (X509_STORE_CTX *)0x0;
        bVar6 = false;
        local_26c = (X509_STORE_CTX *)0x0;
        local_294 = (X509_STORE_CTX *)0x0;
        local_248 = (X509_STORE_CTX *)0x0;
        local_2b4 = (X509_STORE_CTX *)0x0;
        local_270 = (X509_STORE_CTX *)0x0;
        local_2c0 = (X509_STORE_CTX *)0x0;
        local_260 = (X509_STORE_CTX *)0x0;
        local_24c = (X509_STORE_CTX *)0x0;
        local_254 = (X509_STORE_CTX *)0x0;
        local_258 = (X509_STORE_CTX *)0x0;
        local_298 = (X509_STORE_CTX *)0x0;
        local_274 = (X509_STORE_CTX *)0x0;
        local_278 = (X509_STORE_CTX *)0x0;
        local_27c = (X509_STORE_CTX *)0x0;
        local_280 = (X509_STORE_CTX *)0x0;
        local_284 = (X509_STORE_CTX *)0x0;
        local_288 = (X509_STORE_CTX *)0x0;
        local_25c = (X509_STORE_CTX *)0x0;
        local_29c = (byte *)0x0;
        local_2a0 = (X509_STORE_CTX *)0x0;
        local_2b8 = (X509_STORE_CTX *)0x0;
        local_2a4 = (byte *)0x0;
        local_2a8 = (X509_STORE_CTX *)0x0;
        local_2fc = (X509_STORE_CTX *)0x0;
        local_2c8 = 3;
        local_2cc = (X509_STORE_CTX *)0x3;
        local_2d0 = 3;
        local_2d8 = 3;
        local_300 = (X509_STORE_CTX *)0x3;
        local_2e4 = (X509_STORE_CTX *)0x0;
        local_2e8 = (_STACK *)0x0;
        local_2d4 = (X509_STORE_CTX *)0x0;
        local_2f0 = (X509_STORE_CTX *)0x0;
        local_2f4 = (_STACK *)0x0;
        local_2bc = (X509_STORE_CTX *)0x0;
        local_250 = (X509_STORE_CTX *)0x0;
      }
      else {
        local_2bc = (X509_STORE_CTX *)0x0;
        local_22c = (X509_STORE_CTX *)0x0;
        local_264 = (X509_STORE_CTX *)0x0;
        local_230 = (X509_STORE_CTX *)0x0;
        local_234 = (X509_STORE_CTX *)0x0;
        local_2ac = (X509_STORE_CTX *)0x1e;
        local_268 = (X509_STORE_CTX *)0x0;
        local_238 = (X509_STORE_CTX *)0x0;
        bVar5 = false;
        local_23c = (X509_STORE_CTX *)0x0;
        local_240 = (X509_STORE_CTX *)0x0;
        local_244 = (X509_STORE_CTX *)0x0;
        bVar6 = false;
        local_26c = (X509_STORE_CTX *)0x0;
        local_294 = (X509_STORE_CTX *)0x0;
        local_248 = (X509_STORE_CTX *)0x0;
        local_2b4 = (X509_STORE_CTX *)0x0;
        local_270 = (X509_STORE_CTX *)0x0;
        local_2c0 = (X509_STORE_CTX *)0x0;
        local_260 = (X509_STORE_CTX *)0x0;
        local_24c = (X509_STORE_CTX *)0x0;
        local_250 = (X509_STORE_CTX *)0x0;
        local_254 = (X509_STORE_CTX *)0x0;
        local_258 = (X509_STORE_CTX *)0x0;
        local_298 = (X509_STORE_CTX *)0x0;
        local_274 = (X509_STORE_CTX *)0x0;
        local_278 = (X509_STORE_CTX *)0x0;
        local_27c = (X509_STORE_CTX *)0x0;
        local_280 = (X509_STORE_CTX *)0x0;
        local_284 = (X509_STORE_CTX *)0x0;
        local_288 = (X509_STORE_CTX *)0x0;
        local_25c = (X509_STORE_CTX *)0x0;
        local_29c = (byte *)0x0;
        local_2a0 = (X509_STORE_CTX *)0x0;
        local_2b8 = (X509_STORE_CTX *)0x0;
        local_2a4 = (byte *)0x0;
        local_2a8 = (X509_STORE_CTX *)0x0;
        local_2fc = (X509_STORE_CTX *)0x0;
        local_2c8 = 3;
        local_2cc = (X509_STORE_CTX *)0x3;
        local_2d0 = 3;
        local_2d8 = 3;
        local_300 = (X509_STORE_CTX *)0x3;
        local_2e4 = (X509_STORE_CTX *)0x0;
        local_2e8 = (_STACK *)0x0;
        local_2d4 = (X509_STORE_CTX *)0x0;
        local_2f0 = (X509_STORE_CTX *)0x0;
        local_2f4 = (_STACK *)0x0;
        do {
          ppbVar29 = param_2 + 1;
          unaff_EBP = *ppbVar29;
          iVar8 = 8;
          pbVar30 = unaff_EBP;
          pbVar32 = (byte *)"-inform";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar33 = *pbVar30 == *pbVar32;
            pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
            pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
          } while (bVar33);
          if (bVar33) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_08063100;
            ppbVar29 = param_2 + 2;
            local_300 = (X509_STORE_CTX *)str2fmt(param_2[2]);
          }
          else {
            iVar8 = 9;
            pbVar30 = unaff_EBP;
            pbVar32 = (byte *)"-outform";
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              bVar33 = *pbVar30 == *pbVar32;
              pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
              pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
            } while (bVar33);
            if (bVar33) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_08063100;
              ppbVar29 = param_2 + 2;
              local_2d8 = str2fmt(param_2[2]);
            }
            else {
              iVar8 = 9;
              pbVar30 = unaff_EBP;
              pbVar32 = (byte *)"-keyform";
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar33 = *pbVar30 == *pbVar32;
                pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
                pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
              } while (bVar33);
              if (bVar33) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_08063100;
                ppbVar29 = param_2 + 2;
                local_2d0 = str2fmt(param_2[2]);
              }
              else {
                iVar8 = 5;
                pbVar30 = unaff_EBP;
                pbVar32 = &DAT_081f2019;
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  bVar33 = *pbVar30 == *pbVar32;
                  pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
                  pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
                } while (bVar33);
                if (!bVar33) {
                  iVar8 = 8;
                  pbVar30 = unaff_EBP;
                  pbVar32 = (byte *)"-CAform";
                  do {
                    if (iVar8 == 0) break;
                    iVar8 = iVar8 + -1;
                    bVar33 = *pbVar30 == *pbVar32;
                    pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
                    pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
                  } while (bVar33);
                  if (bVar33) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      ppbVar29 = param_2 + 2;
                      local_2cc = (X509_STORE_CTX *)str2fmt(param_2[2]);
                      goto LAB_08062f9e;
                    }
                  }
                  else {
                    iVar8 = 0xb;
                    pbVar30 = unaff_EBP;
                    pbVar32 = (byte *)"-CAkeyform";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar33 = *pbVar30 == *pbVar32;
                      pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
                      pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
                    } while (bVar33);
                    if (bVar33) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        ppbVar29 = param_2 + 2;
                        local_2c8 = str2fmt(param_2[2]);
                        goto LAB_08062f9e;
                      }
                    }
                    else {
                      iVar8 = 8;
                      pbVar30 = unaff_EBP;
                      pbVar32 = (byte *)"-sigopt";
                      do {
                        if (iVar8 == 0) break;
                        iVar8 = iVar8 + -1;
                        bVar33 = *pbVar30 == *pbVar32;
                        pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
                        pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
                      } while (bVar33);
                      if (bVar33) {
                        if ((param_1 != 1) &&
                           ((local_2f4 != (_STACK *)0x0 ||
                            (local_2f4 = sk_new_null(), local_2f4 != (_STACK *)0x0)))) {
                          pXVar36 = (X509_STORE_CTX *)sk_push(local_2f4,param_2[2]);
                          goto joined_r0x08065307;
                        }
                      }
                      else {
                        iVar8 = 6;
                        pbVar30 = unaff_EBP;
                        pbVar32 = (byte *)"-days";
                        do {
                          if (iVar8 == 0) break;
                          iVar8 = iVar8 + -1;
                          bVar33 = *pbVar30 == *pbVar32;
                          pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
                          pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
                        } while (bVar33);
                        if (bVar33) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            ppbVar29 = param_2 + 2;
                            local_2ac = (X509_STORE_CTX *)strtol((char *)param_2[2],(char **)0x0,10)
                            ;
                            if (local_2ac != (X509_STORE_CTX *)0x0) goto LAB_08062f9e;
                            BIO_printf(bio_err,"bad number of days\n",0,0);
                          }
                        }
                        else {
                          iVar8 = 8;
                          pbVar30 = unaff_EBP;
                          pbVar32 = (byte *)"-passin";
                          do {
                            if (iVar8 == 0) break;
                            iVar8 = iVar8 + -1;
                            bVar33 = *pbVar30 == *pbVar32;
                            pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
                            pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
                          } while (bVar33);
                          if (bVar33) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_2ec = (X509_STORE_CTX *)param_2[2];
                              ppbVar29 = param_2 + 2;
                              goto LAB_08062f9e;
                            }
                          }
                          else {
                            iVar8 = 9;
                            pbVar30 = unaff_EBP;
                            pbVar32 = (byte *)"-extfile";
                            do {
                              if (iVar8 == 0) break;
                              iVar8 = iVar8 + -1;
                              bVar33 = *pbVar30 == *pbVar32;
                              pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
                              pbVar32 = pbVar32 + (uint)bVar34 * -2 + 1;
                            } while (bVar33);
                            if (bVar33) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_2f8 = (X509_STORE_CTX *)param_2[2];
                                ppbVar29 = param_2 + 2;
                                goto LAB_08062f9e;
                              }
                            }
                            else {
                              iVar8 = strcmp((char *)unaff_EBP,"-extensions");
                              if (iVar8 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_2c4 = param_2[2];
                                  ppbVar29 = param_2 + 2;
                                  goto LAB_08062f9e;
                                }
                              }
                              else {
                                iVar8 = 0x2d - (uint)*unaff_EBP;
                                if ((((iVar8 == 0) && (unaff_EBP[1] == 0x69)) &&
                                    (unaff_EBP[2] == 0x6e)) && (unaff_EBP[3] == 0)) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_2fc = (X509_STORE_CTX *)param_2[2];
                                    ppbVar29 = param_2 + 2;
                                    goto LAB_08062f9e;
                                  }
                                }
                                else {
                                  iVar12 = strcmp((char *)unaff_EBP,"-out");
                                  if (iVar12 == 0) {
                                    param_1 = param_1 + -1;
                                    if (param_1 != 0) {
                                      local_2a8 = (X509_STORE_CTX *)param_2[2];
                                      ppbVar29 = param_2 + 2;
                                      goto LAB_08062f9e;
                                    }
                                  }
                                  else {
                                    iVar12 = strcmp((char *)unaff_EBP,"-signkey");
                                    if (iVar12 == 0) {
                                      param_1 = param_1 + -1;
                                      if (param_1 != 0) {
                                        local_2a4 = param_2[2];
                                        local_2d4 = (X509_STORE_CTX *)((int)&local_2d4->ctx + 1);
                                        ppbVar29 = param_2 + 2;
                                        bVar3 = true;
                                        local_270 = local_2d4;
                                        goto LAB_08062f9e;
                                      }
                                    }
                                    else if (((iVar8 == 0) && (unaff_EBP[1] == 0x43)) &&
                                            ((unaff_EBP[2] == 0x41 && (unaff_EBP[3] == 0)))) {
                                      param_1 = param_1 + -1;
                                      if (param_1 != 0) {
                                        local_2b8 = (X509_STORE_CTX *)param_2[2];
                                        local_2d4 = (X509_STORE_CTX *)((int)&local_2d4->ctx + 1);
                                        ppbVar29 = param_2 + 2;
                                        bVar3 = true;
                                        local_2b4 = local_2d4;
                                        goto LAB_08062f9e;
                                      }
                                    }
                                    else {
                                      iVar12 = strcmp((char *)unaff_EBP,"-CAkey");
                                      if (iVar12 == 0) {
                                        param_1 = param_1 + -1;
                                        if (param_1 != 0) {
                                          local_2a0 = (X509_STORE_CTX *)param_2[2];
                                          ppbVar29 = param_2 + 2;
                                          goto LAB_08062f9e;
                                        }
                                      }
                                      else {
                                        iVar12 = strcmp((char *)unaff_EBP,"-CAserial");
                                        if (iVar12 == 0) {
                                          param_1 = param_1 + -1;
                                          if (param_1 != 0) {
                                            local_29c = param_2[2];
                                            ppbVar29 = param_2 + 2;
                                            goto LAB_08062f9e;
                                          }
                                        }
                                        else {
                                          iVar12 = strcmp((char *)unaff_EBP,"-set_serial");
                                          if (iVar12 == 0) {
                                            if (param_1 != 1) {
                                              local_2f0 = (X509_STORE_CTX *)
                                                          s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                                           (char *)param_2[2]);
                                              pXVar36 = local_2f0;
                                              goto joined_r0x08065307;
                                            }
                                          }
                                          else {
                                            iVar12 = strcmp((char *)unaff_EBP,"-addtrust");
                                            if (iVar12 == 0) {
                                              param_1 = param_1 + -1;
                                              if (param_1 != 0) {
                                                ppbVar29 = param_2 + 2;
                                                pAVar19 = OBJ_txt2obj((char *)param_2[2],0);
                                                if (pAVar19 != (ASN1_OBJECT *)0x0) {
                                                  if (local_2e8 == (_STACK *)0x0) {
                                                    local_2e8 = sk_new_null();
                                                  }
                                                  sk_push(local_2e8,pAVar19);
                                                  bVar6 = true;
                                                  goto LAB_08062f9e;
                                                }
                                                BIO_printf(bio_err,"Invalid trust object value %s\n"
                                                           ,param_2[2],0);
                                              }
                                            }
                                            else {
                                              iVar12 = strcmp((char *)unaff_EBP,"-addreject");
                                              if (iVar12 == 0) {
                                                param_1 = param_1 + -1;
                                                if (param_1 != 0) {
                                                  ppbVar29 = param_2 + 2;
                                                  pAVar19 = OBJ_txt2obj((char *)param_2[2],0);
                                                  if (pAVar19 != (ASN1_OBJECT *)0x0) {
                                                    if (local_2e4 == (X509_STORE_CTX *)0x0) {
                                                      local_2e4 = (X509_STORE_CTX *)sk_new_null();
                                                    }
                                                    sk_push((_STACK *)local_2e4,pAVar19);
                                                    bVar6 = true;
                                                    goto LAB_08062f9e;
                                                  }
                                                  BIO_printf(bio_err,
                                                  "Invalid reject object value %s\n",param_2[2],
                                                  ppbVar29);
                                                }
                                              }
                                              else {
                                                iVar12 = strcmp((char *)unaff_EBP,"-setalias");
                                                if (iVar12 == 0) {
                                                  param_1 = param_1 + -1;
                                                  if (param_1 != 0) {
                                                    local_25c = (X509_STORE_CTX *)param_2[2];
                                                    ppbVar29 = param_2 + 2;
                                                    bVar6 = true;
                                                    goto LAB_08062f9e;
                                                  }
                                                }
                                                else {
                                                  iVar12 = strcmp((char *)unaff_EBP,"-certopt");
                                                  if (iVar12 == 0) {
                                                    if (param_1 != 1) {
                                                      pXVar36 = (X509_STORE_CTX *)
                                                                set_cert_ex(&local_208,param_2[2],0,
                                                                            0);
joined_r0x08065307:
                                                      ppbVar29 = param_2 + 2;
                                                      param_1 = param_1 + -1;
                                                      if (pXVar36 != (X509_STORE_CTX *)0x0)
                                                      goto LAB_08062f9e;
                                                    }
                                                  }
                                                  else {
                                                    iVar12 = strcmp((char *)unaff_EBP,"-nameopt");
                                                    if (iVar12 != 0) {
                                                      iVar12 = strcmp((char *)unaff_EBP,"-engine");
                                                      if (iVar12 == 0) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 == 0) goto LAB_08063100;
                                                        local_28c = param_2[2];
                                                        ppbVar29 = param_2 + 2;
                                                      }
                                                      else if (((iVar8 == 0) &&
                                                               (unaff_EBP[1] == 0x43)) &&
                                                              (unaff_EBP[2] == 0)) {
                                                        local_2d4 = (X509_STORE_CTX *)
                                                                    ((int)&local_2d4->ctx + 1);
                                                        local_238 = local_2d4;
                                                      }
                                                      else {
                                                        iVar12 = strcmp((char *)unaff_EBP,"-email");
                                                        if (iVar12 == 0) {
                                                          local_2d4 = (X509_STORE_CTX *)
                                                                      ((int)&local_2d4->ctx + 1);
                                                          local_294 = local_2d4;
                                                        }
                                                        else {
                                                          iVar12 = strcmp((char *)unaff_EBP,
                                                                          "-ocsp_uri");
                                                          if (iVar12 == 0) {
                                                            local_2d4 = (X509_STORE_CTX *)
                                                                        ((int)&local_2d4->ctx + 1);
                                                            local_26c = local_2d4;
                                                          }
                                                          else {
                                                            iVar12 = strcmp((char *)unaff_EBP,
                                                                            "-serial");
                                                            if (iVar12 == 0) {
                                                              local_2d4 = (X509_STORE_CTX *)
                                                                          ((int)&local_2d4->ctx + 1)
                                                              ;
                                                              local_284 = local_2d4;
                                                            }
                                                            else {
                                                              iVar12 = strcmp((char *)unaff_EBP,
                                                                              "-next_serial");
                                                              if (iVar12 == 0) {
                                                                local_2d4 = (X509_STORE_CTX *)
                                                                            ((int)&local_2d4->ctx +
                                                                            1);
                                                                local_298 = local_2d4;
                                                              }
                                                              else {
                                                                iVar12 = strcmp((char *)unaff_EBP,
                                                                                "-modulus");
                                                                if (iVar12 == 0) {
                                                                  local_2d4 = (X509_STORE_CTX *)
                                                                              ((int)&local_2d4->ctx
                                                                              + 1);
                                                                  local_234 = local_2d4;
                                                                }
                                                                else {
                                                                  iVar12 = strcmp((char *)unaff_EBP,
                                                                                  "-pubkey");
                                                                  if (iVar12 == 0) {
                                                                    local_2d4 = (X509_STORE_CTX *)
                                                                                ((int)&local_2d4->
                                                                                       ctx + 1);
                                                                    local_230 = local_2d4;
                                                                  }
                                                                  else {
                                                                    iVar12 = strcmp((char *)
                                                  unaff_EBP,"-x509toreq");
                                                  if (iVar12 == 0) {
                                                    local_2d4 = (X509_STORE_CTX *)
                                                                ((int)&local_2d4->ctx + 1);
                                                    local_268 = local_2d4;
                                                  }
                                                  else {
                                                    iVar12 = strcmp((char *)unaff_EBP,"-text");
                                                    if (iVar12 == 0) {
                                                      local_2d4 = (X509_STORE_CTX *)
                                                                  ((int)&local_2d4->ctx + 1);
                                                      local_288 = local_2d4;
                                                    }
                                                    else {
                                                      iVar12 = strcmp((char *)unaff_EBP,"-hash");
                                                      if ((iVar12 == 0) ||
                                                         (iVar12 = strcmp((char *)unaff_EBP,
                                                                          "-subject_hash"),
                                                         iVar12 == 0)) {
                                                        local_2d4 = (X509_STORE_CTX *)
                                                                    ((int)&local_2d4->ctx + 1);
                                                        local_258 = local_2d4;
                                                      }
                                                      else {
                                                        iVar12 = strcmp((char *)unaff_EBP,
                                                                        "-subject_hash_old");
                                                        if (iVar12 == 0) {
                                                          local_2d4 = (X509_STORE_CTX *)
                                                                      ((int)&local_2d4->ctx + 1);
                                                          local_24c = local_2d4;
                                                        }
                                                        else {
                                                          iVar12 = strcmp((char *)unaff_EBP,
                                                                          "-issuer_hash");
                                                          if (iVar12 == 0) {
                                                            local_2d4 = (X509_STORE_CTX *)
                                                                        ((int)&local_2d4->ctx + 1);
                                                            local_254 = local_2d4;
                                                          }
                                                          else {
                                                            iVar12 = strcmp((char *)unaff_EBP,
                                                                            "-issuer_hash_old");
                                                            if (iVar12 == 0) {
                                                              local_2d4 = (X509_STORE_CTX *)
                                                                          ((int)&local_2d4->ctx + 1)
                                                              ;
                                                              local_260 = local_2d4;
                                                            }
                                                            else {
                                                              iVar12 = strcmp((char *)unaff_EBP,
                                                                              "-subject");
                                                              if (iVar12 == 0) {
                                                                local_2d4 = (X509_STORE_CTX *)
                                                                            ((int)&local_2d4->ctx +
                                                                            1);
                                                                local_280 = local_2d4;
                                                              }
                                                              else {
                                                                iVar12 = strcmp((char *)unaff_EBP,
                                                                                "-issuer");
                                                                if (iVar12 == 0) {
                                                                  local_2d4 = (X509_STORE_CTX *)
                                                                              ((int)&local_2d4->ctx
                                                                              + 1);
                                                                  local_27c = local_2d4;
                                                                }
                                                                else {
                                                                  iVar12 = strcmp((char *)unaff_EBP,
                                                                                  "-fingerprint");
                                                                  if (iVar12 == 0) {
                                                                    local_2d4 = (X509_STORE_CTX *)
                                                                                ((int)&local_2d4->
                                                                                       ctx + 1);
                                                                    local_22c = local_2d4;
                                                                  }
                                                                  else {
                                                                    iVar12 = strcmp((char *)
                                                  unaff_EBP,"-dates");
                                                  if (iVar12 == 0) {
                                                    local_278 = (X509_STORE_CTX *)
                                                                ((int)&local_2d4->ctx + 1);
                                                    local_2d4 = (X509_STORE_CTX *)
                                                                ((int)&local_2d4->ctx + 2);
                                                    local_274 = local_2d4;
                                                  }
                                                  else {
                                                    iVar12 = strcmp((char *)unaff_EBP,"-purpose");
                                                    if (iVar12 == 0) {
                                                      local_2d4 = (X509_STORE_CTX *)
                                                                  ((int)&local_2d4->ctx + 1);
                                                      local_264 = local_2d4;
                                                    }
                                                    else {
                                                      iVar12 = strcmp((char *)unaff_EBP,"-startdate"
                                                                     );
                                                      if (iVar12 == 0) {
                                                        local_2d4 = (X509_STORE_CTX *)
                                                                    ((int)&local_2d4->ctx + 1);
                                                        local_278 = local_2d4;
                                                      }
                                                      else {
                                                        iVar12 = strcmp((char *)unaff_EBP,"-enddate"
                                                                       );
                                                        if (iVar12 == 0) {
                                                          local_2d4 = (X509_STORE_CTX *)
                                                                      ((int)&local_2d4->ctx + 1);
                                                          local_274 = local_2d4;
                                                        }
                                                        else {
                                                          iVar12 = strcmp((char *)unaff_EBP,
                                                                          "-checkend");
                                                          if (iVar12 == 0) {
                                                            param_1 = param_1 + -1;
                                                            if (param_1 == 0) goto LAB_08063100;
                                                            ppbVar29 = param_2 + 2;
                                                            local_224 = strtol((char *)param_2[2],
                                                                               (char **)0x0,10);
                                                            bVar4 = true;
                                                          }
                                                          else {
                                                            iVar12 = strcmp((char *)unaff_EBP,
                                                                            "-noout");
                                                            if (iVar12 == 0) {
                                                              local_2d4 = (X509_STORE_CTX *)
                                                                          ((int)&local_2d4->ctx + 1)
                                                              ;
                                                              local_2c0 = local_2d4;
                                                            }
                                                            else {
                                                              iVar12 = strcmp((char *)unaff_EBP,
                                                                              "-trustout");
                                                              if (iVar12 == 0) {
                                                                bVar6 = true;
                                                              }
                                                              else {
                                                                iVar12 = strcmp((char *)unaff_EBP,
                                                                                "-clrtrust");
                                                                if (iVar12 == 0) {
                                                                  local_2d4 = (X509_STORE_CTX *)
                                                                              ((int)&local_2d4->ctx
                                                                              + 1);
                                                                  local_244 = local_2d4;
                                                                }
                                                                else {
                                                                  iVar12 = strcmp((char *)unaff_EBP,
                                                                                  "-clrreject");
                                                                  if (iVar12 == 0) {
                                                                    local_2d4 = (X509_STORE_CTX *)
                                                                                ((int)&local_2d4->
                                                                                       ctx + 1);
                                                                    local_240 = local_2d4;
                                                                  }
                                                                  else {
                                                                    iVar12 = strcmp((char *)
                                                  unaff_EBP,"-alias");
                                                  if (iVar12 == 0) {
                                                    local_2d4 = (X509_STORE_CTX *)
                                                                ((int)&local_2d4->ctx + 1);
                                                    local_23c = local_2d4;
                                                  }
                                                  else {
                                                    iVar12 = strcmp((char *)unaff_EBP,
                                                                    "-CAcreateserial");
                                                    if (iVar12 == 0) {
                                                      local_2d4 = (X509_STORE_CTX *)
                                                                  ((int)&local_2d4->ctx + 1);
                                                      local_248 = local_2d4;
                                                    }
                                                    else {
                                                      iVar12 = strcmp((char *)unaff_EBP,"-clrext");
                                                      if (iVar12 == 0) {
                                                        bVar5 = true;
                                                      }
                                                      else {
                                                        iVar12 = strcmp((char *)unaff_EBP,"-crlext")
                                                        ;
                                                        if (iVar12 == 0) {
                                                          BIO_printf(bio_err,
                                                  "use -clrext instead of -crlext\n",unaff_EBP,
                                                  unaff_EBP);
                                                  bVar5 = true;
                                                  }
                                                  else {
                                                    iVar12 = strcmp((char *)unaff_EBP,"-ocspid");
                                                    if (iVar12 == 0) {
                                                      local_2d4 = (X509_STORE_CTX *)
                                                                  ((int)&local_2d4->ctx + 1);
                                                      local_250 = local_2d4;
                                                    }
                                                    else {
                                                      unaff_EBP = unaff_EBP + 1;
                                                      local_2bc = (X509_STORE_CTX *)
                                                                  EVP_get_digestbyname
                                                                            ((char *)unaff_EBP);
                                                      if (local_2bc == (X509_STORE_CTX *)0x0) {
                                                        BIO_printf(bio_err,"unknown option %s\n",
                                                                   *ppbVar29,iVar8);
                                                        goto LAB_08063100;
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_08062f9e;
                                                  }
                                                  if (param_1 != 1) {
                                                    pXVar36 = (X509_STORE_CTX *)
                                                              set_name_ex(&local_20c,param_2[2],0,0)
                                                    ;
                                                    goto joined_r0x08065307;
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
LAB_08063100:
                  if (x509_usage._0_4_ != 0) {
                    puVar25 = x509_usage;
                    iVar8 = x509_usage._0_4_;
                    do {
                      puVar25 = (undefined1 *)((int)puVar25 + 4);
                      BIO_printf(bio_err,"%s",iVar8);
                      iVar8 = *(int *)puVar25;
                    } while (iVar8 != 0);
                  }
                  goto LAB_08063130;
                }
                reqfile = 1;
                bVar3 = true;
              }
            }
          }
LAB_08062f9e:
          param_1 = param_1 + -1;
          bVar33 = param_1 == 0;
          param_2 = ppbVar29;
        } while (!bVar33);
      }
      pXVar36 = (X509_STORE_CTX *)0x0;
      uVar31 = setup_engine(bio_err,local_28c,0);
      if (bVar3) {
        pXVar36 = (X509_STORE_CTX *)0x0;
        app_RAND_load_file(0,bio_err,0);
      }
      ERR_load_crypto_strings();
      iVar8 = app_passwd(bio_err,local_2ec,0,&local_210,0);
      if (iVar8 == 0) {
        pcVar35 = "Error getting password\n";
        local_2b4 = pXVar36;
LAB_0806344f:
        BIO_printf(bio_err,pcVar35,local_2b4);
LAB_08063130:
        local_2ec = (X509_STORE_CTX *)0x0;
LAB_08063138:
        local_300 = (X509_STORE_CTX *)0x0;
        pXVar28 = (X509_STORE_CTX *)0x0;
        local_304 = (EVP_PKEY *)0x0;
        local_2a8 = (X509_STORE_CTX *)0x0;
        local_2fc = (X509_STORE_CTX *)0x0;
        x = (X509_STORE_CTX *)0x0;
        local_2f8 = (X509_STORE_CTX *)0x0;
        uVar31 = 1;
      }
      else {
        pXVar36 = (X509_STORE_CTX *)X509_STORE_set_default_paths(local_308);
        if (pXVar36 == (X509_STORE_CTX *)0x0) {
          ERR_print_errors(bio_err);
          goto LAB_08063130;
        }
        if ((local_2a0 == (X509_STORE_CTX *)0x0) &&
           (pXVar36 = local_2b4, local_2b4 != (X509_STORE_CTX *)0x0)) {
          if (local_2cc != (X509_STORE_CTX *)0x3) {
            pcVar35 = "need to specify a CAkey if using the CA command\n";
            goto LAB_0806344f;
          }
          local_2a0 = local_2b8;
          pXVar36 = local_2b8;
        }
        if (local_2f8 != (X509_STORE_CTX *)0x0) {
          local_204.flags = -1;
          local_2ec = (X509_STORE_CTX *)NCONF_new((CONF_METHOD *)0x0);
          iVar8 = NCONF_load((CONF *)local_2ec,(char *)local_2f8,&local_204.flags);
          if (iVar8 == 0) {
            if (local_204.flags < 1) {
              BIO_printf(bio_err,"error loading the config file \'%s\'\n",local_2f8,local_204.flags)
              ;
            }
            else {
              BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_204.flags,
                         local_2f8);
            }
          }
          else {
            if ((local_2c4 == (byte *)0x0) &&
               (local_2c4 = (byte *)NCONF_get_string((CONF *)local_2ec,"default","extensions"),
               local_2c4 == (byte *)0x0)) {
              ERR_clear_error();
              local_2c4 = (byte *)0x822e390;
            }
            X509V3_set_ctx((X509V3_CTX *)&local_1e8,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,
                           (X509_CRL *)0x0,1);
            X509V3_set_nconf((X509V3_CTX *)&local_1e8,(CONF *)local_2ec);
            pXVar36 = (X509_STORE_CTX *)
                      X509V3_EXT_add_nconf
                                ((CONF *)local_2ec,(X509V3_CTX *)&local_1e8,(char *)local_2c4,
                                 (X509 *)0x0);
            pXVar11 = local_2ec;
            if (pXVar36 != (X509_STORE_CTX *)0x0) goto LAB_08063615;
            BIO_printf(bio_err,"Error Loading extension section %s\n",local_2c4,unaff_EBP);
            ERR_print_errors(bio_err);
          }
          goto LAB_08063138;
        }
        local_2ec = (X509_STORE_CTX *)0x0;
        pXVar11 = local_2f8;
LAB_08063615:
        if (reqfile == 0) {
          pcVar35 = "Certificate";
          pXVar28 = (X509_STORE_CTX *)
                    load_cert(bio_err,local_2fc,local_300,0,uVar31,"Certificate",pXVar36,pXVar36);
          x = pXVar28;
          if (pXVar28 == (X509_STORE_CTX *)0x0) {
LAB_0806478f:
            local_300 = (X509_STORE_CTX *)0x0;
            pXVar28 = (X509_STORE_CTX *)0x0;
            local_304 = (EVP_PKEY *)0x0;
            local_2a8 = (X509_STORE_CTX *)0x0;
            local_2fc = (X509_STORE_CTX *)0x0;
            local_2f8 = (X509_STORE_CTX *)0x0;
            uVar31 = 1;
          }
          else {
            local_2f8 = (X509_STORE_CTX *)0x0;
            pXVar18 = extraout_ECX_00;
LAB_0806382b:
            local_2fc = (X509_STORE_CTX *)0x0;
            if (local_2b4 != (X509_STORE_CTX *)0x0) {
              pcVar35 = "CA Certificate";
              local_2fc = (X509_STORE_CTX *)
                          load_cert(bio_err,local_2b8,local_2cc,0,uVar31,"CA Certificate",pXVar28,
                                    pXVar28);
              pXVar18 = extraout_ECX_29;
              pXVar36 = pXVar28;
              if (local_2fc == (X509_STORE_CTX *)0x0) {
                local_300 = (X509_STORE_CTX *)0x0;
                pXVar28 = (X509_STORE_CTX *)0x0;
                local_304 = (EVP_PKEY *)0x0;
                local_2a8 = (X509_STORE_CTX *)0x0;
                uVar31 = 1;
                goto LAB_08063163;
              }
            }
            if ((local_2c0 == (X509_STORE_CTX *)0x0 || local_288 != (X509_STORE_CTX *)0x0) ||
               (pXVar28 = (X509_STORE_CTX *)0x0, local_298 != (X509_STORE_CTX *)0x0)) {
              OBJ_create("2.99999.3","SET.ex3","SET x509v3 extension 3");
              pBVar9 = BIO_s_file();
              pXVar28 = (X509_STORE_CTX *)BIO_new(pBVar9);
              if (pXVar28 == (X509_STORE_CTX *)0x0) {
                ERR_print_errors(bio_err);
LAB_080639df:
                local_300 = (X509_STORE_CTX *)0x0;
                local_304 = (EVP_PKEY *)0x0;
                local_2a8 = (X509_STORE_CTX *)0x0;
                uVar31 = 1;
                goto LAB_08063163;
              }
              if (local_2a8 == (X509_STORE_CTX *)0x0) {
                pXVar36 = (X509_STORE_CTX *)0x0;
                pcVar35 = (char *)0x6a;
                BIO_ctrl((BIO *)pXVar28,0x6a,0,stdout);
                pXVar18 = extraout_ECX_28;
              }
              else {
                pXVar36 = (X509_STORE_CTX *)0x5;
                pcVar35 = (char *)0x6c;
                lVar10 = BIO_ctrl((BIO *)pXVar28,0x6c,5,local_2a8);
                pXVar18 = extraout_ECX_04;
                if (lVar10 < 1) {
                  perror((char *)local_2a8);
                  goto LAB_080639df;
                }
              }
            }
            if (local_25c != (X509_STORE_CTX *)0x0) {
              pXVar36 = (X509_STORE_CTX *)0xffffffff;
              X509_alias_set1((X509 *)x,(uchar *)local_25c,-1);
              pXVar18 = extraout_ECX_01;
              pcVar35 = (char *)local_25c;
            }
            if (local_244 != (X509_STORE_CTX *)0x0) {
              X509_trust_clear((X509 *)x);
              pXVar18 = extraout_ECX_30;
            }
            if (local_240 != (X509_STORE_CTX *)0x0) {
              X509_reject_clear((X509 *)x);
              pXVar18 = extraout_ECX_31;
            }
            if (local_2e8 != (_STACK *)0x0) {
              for (pXVar11 = (X509_STORE_CTX *)0x0; iVar8 = sk_num(local_2e8),
                  pXVar18 = extraout_ECX_02, (int)pXVar11 < iVar8;
                  pXVar11 = (X509_STORE_CTX *)((int)&pXVar11->ctx + 1)) {
                pcVar35 = (char *)sk_value(local_2e8,(int)pXVar11);
                X509_add1_trust_object((X509 *)x,(ASN1_OBJECT *)pcVar35);
              }
            }
            pXVar13 = local_2e4;
            if (local_2e4 != (X509_STORE_CTX *)0x0) {
              for (pXVar11 = (X509_STORE_CTX *)0x0;
                  pXVar13 = (X509_STORE_CTX *)sk_num((_STACK *)local_2e4), pXVar18 = extraout_ECX_03
                  , (int)pXVar11 < (int)pXVar13;
                  pXVar11 = (X509_STORE_CTX *)((int)&pXVar11->ctx + 1)) {
                pcVar35 = (char *)sk_value((_STACK *)local_2e4,(int)pXVar11);
                X509_add1_reject_object((X509 *)x,(ASN1_OBJECT *)pcVar35);
              }
            }
            if (local_2d4 != (X509_STORE_CTX *)0x0) {
              pcVar27 = (char *)0x0;
              local_300 = (X509_STORE_CTX *)0x0;
              local_2cc = (X509_STORE_CTX *)0x1;
              local_304 = (EVP_PKEY *)0x0;
              local_2a8 = (X509_STORE_CTX *)0x0;
              pXVar13 = (X509_STORE_CTX *)((int)local_2ac * 0x15180);
LAB_08063c10:
              pXVar37 = local_20c;
              if (local_27c == local_2cc) {
                pXVar11 = x;
                pXVar17 = X509_get_issuer_name((X509 *)x);
                print_name(local_2e0,"issuer= ",pXVar17,pXVar37,pXVar11,pcVar35,pXVar36);
                pXVar18 = extraout_ECX_43;
              }
              else if (local_280 == local_2cc) {
                pXVar11 = x;
                pXVar17 = X509_get_subject_name((X509 *)x);
                print_name(local_2e0,"subject= ",pXVar17,pXVar37,pXVar11,pcVar35,pXVar36);
                pXVar18 = extraout_ECX_42;
              }
              else if (local_284 == local_2cc) {
                BIO_printf((BIO *)local_2e0,"serial=",pXVar11,pXVar11);
                pcVar27 = (char *)x;
                pXVar37 = (X509_STORE_CTX *)X509_get_serialNumber((X509 *)x);
                i2a_ASN1_INTEGER((BIO *)local_2e0,(ASN1_INTEGER *)pXVar37);
                pcVar35 = &DAT_081f11d3;
                BIO_printf((BIO *)local_2e0,"\n");
                pXVar18 = extraout_ECX_41;
                pXVar36 = pXVar11;
              }
              else if (local_298 == local_2cc) {
                ai = X509_get_serialNumber((X509 *)x);
                pBVar22 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
                if (((pBVar22 == (BIGNUM *)0x0) ||
                    (pXVar36 = (X509_STORE_CTX *)BN_add_word(pBVar22,1),
                    pXVar36 == (X509_STORE_CTX *)0x0)) ||
                   (pXVar11 = (X509_STORE_CTX *)BN_to_ASN1_INTEGER(pBVar22,(ASN1_INTEGER *)0x0),
                   pXVar11 == (X509_STORE_CTX *)0x0)) goto LAB_08063e8b;
                BN_free(pBVar22);
                pcVar27 = (char *)pXVar11;
                i2a_ASN1_INTEGER((BIO *)pXVar28,(ASN1_INTEGER *)pXVar11);
                ASN1_INTEGER_free((ASN1_INTEGER *)pXVar11);
                pcVar35 = &DAT_081f11d3;
                BIO_puts((BIO *)pXVar28,"\n");
                pXVar18 = extraout_ECX_40;
                pXVar37 = pXVar28;
              }
              else if ((local_294 == local_2cc) || (local_26c == local_2cc)) {
                if (local_294 == local_2cc) {
                  pcVar27 = (char *)X509_get1_email((X509 *)x);
                }
                else {
                  pcVar27 = (char *)X509_get1_ocsp((X509 *)x);
                }
                for (pXVar37 = (X509_STORE_CTX *)0x0; iVar8 = sk_num((_STACK *)pcVar27),
                    (int)pXVar37 < iVar8; pXVar37 = (X509_STORE_CTX *)((int)&pXVar37->ctx + 1)) {
                  pXVar36 = (X509_STORE_CTX *)sk_value((_STACK *)pcVar27,(int)pXVar37);
                  pcVar35 = &DAT_081ed0e4;
                  BIO_printf((BIO *)local_2e0,"%s\n");
                }
                X509_email_free((stack_st_OPENSSL_STRING *)pcVar27);
                pXVar18 = extraout_ECX_05;
              }
              else {
                pXVar37 = pXVar11;
                if (local_23c == local_2cc) {
                  pXVar36 = (X509_STORE_CTX *)X509_alias_get0((X509 *)x,(int *)0x0);
                  if (pXVar36 == (X509_STORE_CTX *)0x0) {
                    pcVar35 = "<No Alias>\n";
                    pXVar36 = extraout_EDX_05;
                    BIO_puts((BIO *)local_2e0,"<No Alias>\n");
                    pXVar18 = extraout_ECX_46;
                  }
                  else {
                    pcVar35 = &DAT_081ed0e4;
                    BIO_printf((BIO *)local_2e0,"%s\n",pXVar36,extraout_ECX_44);
                    pXVar18 = extraout_ECX_45;
                  }
                }
                else {
                  if (local_258 == local_2cc) {
                    pXVar36 = (X509_STORE_CTX *)X509_subject_name_hash((X509 *)x);
                  }
                  else if (local_24c == local_2cc) {
                    pXVar36 = (X509_STORE_CTX *)X509_subject_name_hash_old((X509 *)x);
                  }
                  else if (local_254 == local_2cc) {
                    pXVar36 = (X509_STORE_CTX *)X509_issuer_name_hash((X509 *)x);
                  }
                  else {
                    if (local_260 != local_2cc) {
                      if (local_264 == local_2cc) {
                        pcVar35 = "Certificate purposes:\n";
                        BIO_printf((BIO *)local_2e0,"Certificate purposes:\n",pXVar13,pXVar13);
                        for (local_25c = (X509_STORE_CTX *)0x0; iVar8 = X509_PURPOSE_get_count(),
                            pXVar18 = extraout_ECX_35, pXVar37 = pXVar11, pXVar36 = pXVar13,
                            (int)local_25c < iVar8;
                            local_25c = (X509_STORE_CTX *)((int)local_25c + 1)) {
                          xp = X509_PURPOSE_get0((int)local_25c);
                          iVar8 = X509_PURPOSE_get_id(xp);
                          pXVar11 = (X509_STORE_CTX *)X509_PURPOSE_get0_name(xp);
                          iVar12 = X509_check_purpose((X509 *)x,iVar8,0);
                          iVar20 = BIO_printf((BIO *)local_2e0,"%s%s : ",pXVar11,&DAT_081ec74a);
                          if (iVar12 == 1) {
                            BIO_printf((BIO *)local_2e0,"Yes\n",iVar20,iVar20);
                          }
                          else if (iVar12 == 0) {
                            BIO_printf((BIO *)local_2e0,"No\n",iVar20,iVar20);
                          }
                          else {
                            BIO_printf((BIO *)local_2e0,"Yes (WARNING code=%d)\n",iVar12,iVar20);
                          }
                          pcVar27 = (char *)X509_check_purpose((X509 *)x,iVar8,1);
                          pXVar13 = (X509_STORE_CTX *)
                                    BIO_printf((BIO *)local_2e0,"%s%s : ",pXVar11," CA");
                          if ((X509_STORE_CTX *)pcVar27 == (X509_STORE_CTX *)0x1) {
                            pcVar35 = &DAT_081f2215;
                            BIO_printf((BIO *)local_2e0,"Yes\n",pXVar13,pXVar13);
                          }
                          else {
                            pXVar13 = (X509_STORE_CTX *)pcVar27;
                            if ((X509_STORE_CTX *)pcVar27 == (X509_STORE_CTX *)0x0) {
                              pcVar35 = &DAT_081f2211;
                              BIO_printf((BIO *)local_2e0,"No\n",0,0);
                            }
                            else {
                              pcVar35 = "Yes (WARNING code=%d)\n";
                              BIO_printf((BIO *)local_2e0,"Yes (WARNING code=%d)\n",pcVar27,pXVar11)
                              ;
                            }
                          }
                        }
                      }
                      else if (local_2cc == local_234) {
                        pXVar37 = (X509_STORE_CTX *)X509_get_pubkey((X509 *)x);
                        if (pXVar37 == (X509_STORE_CTX *)0x0) {
                          pcVar35 = "Modulus=unavailable\n";
                          pXVar37 = extraout_ECX_33;
                          goto LAB_08064316;
                        }
                        BIO_printf((BIO *)local_2e0,"Modulus=",extraout_EDX_02,extraout_EDX_02);
                        pXVar2 = pXVar37->ctx;
                        if (pXVar2 == (X509_STORE *)0x6) {
                          pXVar36 = (X509_STORE_CTX *)
                                    BN_print(local_2e0,(BIGNUM *)pXVar37->param->purpose);
                        }
                        else if (pXVar2 == (X509_STORE *)0x74) {
                          pXVar36 = (X509_STORE_CTX *)
                                    BN_print(local_2e0,(BIGNUM *)pXVar37->param->depth);
                        }
                        else {
                          pXVar36 = (X509_STORE_CTX *)
                                    BIO_printf((BIO *)local_2e0,"Wrong Algorithm type",pXVar2,pXVar2
                                              );
                        }
                        pcVar35 = &DAT_081f11d3;
                        BIO_printf((BIO *)local_2e0,"\n",pXVar36,pXVar36);
                        EVP_PKEY_free((EVP_PKEY *)pXVar37);
                        pXVar18 = extraout_ECX_34;
                      }
                      else if (local_230 == local_2cc) {
                        pXVar37 = (X509_STORE_CTX *)X509_get_pubkey((X509 *)x);
                        if (pXVar37 == (X509_STORE_CTX *)0x0) {
                          pcVar35 = "Error getting public key\n";
                          goto LAB_08064316;
                        }
                        pcVar35 = (char *)pXVar37;
                        pXVar36 = pXVar37;
                        PEM_write_bio_PUBKEY((BIO *)local_2e0,(EVP_PKEY *)pXVar37);
                        EVP_PKEY_free((EVP_PKEY *)pXVar37);
                        pXVar18 = extraout_ECX_22;
                      }
                      else if (local_238 == local_2cc) {
                        pXVar17 = X509_get_subject_name((X509 *)x);
                        X509_NAME_oneline(pXVar17,local_120,0x100);
                        BIO_printf((BIO *)local_2e0,"/* subject:%s */\n",local_120);
                        pXVar17 = X509_get_issuer_name((X509 *)x);
                        X509_NAME_oneline(pXVar17,local_120,0x100);
                        BIO_printf((BIO *)local_2e0,"/* issuer :%s */\n",local_120);
                        iVar8 = i2d_X509((X509 *)x,(uchar **)0x0);
                        pXVar37 = (X509_STORE_CTX *)CRYPTO_malloc(iVar8,"x509.c",0x369);
                        local_1e8.ctx = (X509_STORE *)pXVar37;
                        pXVar17 = X509_get_subject_name((X509 *)x);
                        uVar24 = i2d_X509_NAME(pXVar17,(uchar **)&local_1e8);
                        uVar16 = BIO_printf((BIO *)local_2e0,
                                            "unsigned char XXX_subject_name[%d]={\n",uVar24);
                        uVar15 = extraout_ECX_11;
                        local_1e8.ctx = (X509_STORE *)pXVar37;
                        for (uVar26 = 0; (int)uVar26 < (int)uVar24; uVar26 = uVar26 + 1) {
                          BIO_printf((BIO *)local_2e0,"0x%02X,",
                                     (uint)*(uchar *)((int)((int)local_1e8.ctx + 0x58) +
                                                     (uVar26 - 0x58)),uVar16);
                          uVar16 = uVar26 & 0xf;
                          uVar15 = extraout_ECX_12;
                          if (uVar16 == 0xf) {
                            uVar16 = BIO_printf((BIO *)local_2e0,"\n",0xf,0xf);
                            uVar15 = extraout_ECX_13;
                          }
                        }
                        iVar8 = 0;
                        if ((int)uVar24 < 0) {
                          uVar24 = 0;
                        }
                        if ((uVar24 & 0xf) != 0) {
                          iVar8 = BIO_printf((BIO *)local_2e0,"\n",uVar15,uVar15);
                        }
                        BIO_printf((BIO *)local_2e0,"};\n",iVar8,iVar8);
                        uVar24 = i2d_X509_PUBKEY((X509_PUBKEY *)x->ctx->get_issuer,
                                                 (uchar **)&local_1e8);
                        uVar16 = BIO_printf((BIO *)local_2e0,"unsigned char XXX_public_key[%d]={\n",
                                            uVar24);
                        uVar15 = extraout_ECX_14;
                        local_1e8.ctx = (X509_STORE *)pXVar37;
                        for (uVar26 = 0; (int)uVar26 < (int)uVar24; uVar26 = uVar26 + 1) {
                          BIO_printf((BIO *)local_2e0,"0x%02X,",
                                     (uint)*(uchar *)((int)((int)local_1e8.ctx + 0x58) +
                                                     (uVar26 - 0x58)),uVar16);
                          uVar16 = uVar26 & 0xf;
                          uVar15 = extraout_ECX_15;
                          if (uVar16 == 0xf) {
                            uVar16 = BIO_printf((BIO *)local_2e0,"\n",0xf,0xf);
                            uVar15 = extraout_ECX_16;
                          }
                        }
                        iVar8 = 0;
                        if ((int)uVar24 < 0) {
                          uVar24 = 0;
                        }
                        if ((uVar24 & 0xf) != 0) {
                          iVar8 = BIO_printf((BIO *)local_2e0,"\n",uVar15,uVar15);
                        }
                        BIO_printf((BIO *)local_2e0,"};\n",iVar8,iVar8);
                        uVar24 = i2d_X509((X509 *)x,(uchar **)&local_1e8);
                        uVar16 = BIO_printf((BIO *)local_2e0,"unsigned char XXX_certificate[%d]={\n"
                                            ,uVar24);
                        pXVar36 = extraout_ECX_17;
                        local_1e8.ctx = (X509_STORE *)pXVar37;
                        for (uVar26 = 0; (int)uVar26 < (int)uVar24; uVar26 = uVar26 + 1) {
                          BIO_printf((BIO *)local_2e0,"0x%02X,",
                                     (uint)*(uchar *)((int)((int)local_1e8.ctx + 0x58) +
                                                     (uVar26 - 0x58)),uVar16);
                          uVar16 = uVar26 & 0xf;
                          pXVar36 = extraout_ECX_18;
                          if (uVar16 == 0xf) {
                            uVar16 = BIO_printf((BIO *)local_2e0,"\n",0xf,0xf);
                            pXVar36 = extraout_ECX_19;
                          }
                        }
                        if ((int)uVar24 < 0) {
                          uVar24 = 0;
                        }
                        pcVar27 = (char *)(uVar24 & 0xf);
                        if ((X509_STORE_CTX *)pcVar27 != (X509_STORE_CTX *)0x0) {
                          BIO_printf((BIO *)local_2e0,"\n",pcVar27,pcVar27);
                          pXVar36 = extraout_ECX_20;
                        }
                        pcVar35 = &DAT_081ec46c;
                        BIO_printf((BIO *)local_2e0,"};\n",pXVar36,pXVar36);
                        CRYPTO_free(pXVar37);
                        pXVar18 = extraout_ECX_21;
                      }
                      else {
                        if (local_288 != local_2cc) {
                          if (local_278 == local_2cc) {
                            BIO_puts((BIO *)local_2e0,"notBefore=");
                            pAVar23 = ((X509_VAL *)x->ctx->verify)->notBefore;
                          }
                          else {
                            if (local_274 != local_2cc) {
                              if (local_2cc == local_22c) {
                                pXVar36 = local_2bc;
                                if (local_2bc == (X509_STORE_CTX *)0x0) {
                                  pXVar36 = (X509_STORE_CTX *)EVP_sha1();
                                }
                                iVar8 = X509_digest((X509 *)x,(EVP_MD *)pXVar36,local_160,
                                                    (uint *)&local_1e8);
                                if (iVar8 != 0) {
                                  pcVar27 = (char *)0x0;
                                  iVar8 = EVP_MD_type((EVP_MD *)pXVar36);
                                  pXVar36 = (X509_STORE_CTX *)OBJ_nid2sn(iVar8);
                                  pcVar35 = "%s Fingerprint=";
                                  BIO_printf((BIO *)local_2e0,"%s Fingerprint=");
                                  pXVar18 = extraout_ECX_08;
                                  while (pXVar37 = (X509_STORE_CTX *)0x3a,
                                        (int)pcVar27 < (int)local_1e8.ctx) {
                                    pcVar27 = (char *)((int)(X509_STORE **)pcVar27 + 1);
                                    uVar15 = 10;
                                    if (local_1e8.ctx != (X509_STORE *)pcVar27) {
                                      uVar15 = 0x3a;
                                    }
                                    pXVar36 = (X509_STORE_CTX *)
                                              (uint)(byte)((undefined *)
                                                          ((int)&local_1e8.ex_data.dummy + 3))
                                                          [(int)pcVar27];
                                    pcVar35 = "%02X%c";
                                    BIO_printf((BIO *)local_2e0,"%02X%c",pXVar36,uVar15);
                                    pXVar18 = extraout_ECX_09;
                                  }
                                  goto LAB_08063bfd;
                                }
                                uVar31 = 1;
                                BIO_printf(bio_err,"out of memory\n",0,0);
                                goto LAB_08063163;
                              }
                              if ((local_270 == local_2cc) && (local_268 == (X509_STORE_CTX *)0x0))
                              {
                                BIO_printf(bio_err,"Getting Private key\n",pcVar27,pcVar27);
                                if ((local_2a8 == (X509_STORE_CTX *)0x0) &&
                                   (local_2a8 = (X509_STORE_CTX *)
                                                load_key(bio_err,local_2a4,local_2d0,0,local_210,
                                                         uVar31,"Private key",pXVar11),
                                   local_2a8 == (X509_STORE_CTX *)0x0)) {
LAB_08063e8b:
                                  uVar31 = 1;
                                }
                                else {
                                  if (!bVar3) {
                    /* WARNING: Subroutine does not return */
                                    __assert_fail("need_rand","x509.c",0x3c6,
                                                  __PRETTY_FUNCTION___16775);
                                  }
                                  pXVar37 = (X509_STORE_CTX *)X509_get_pubkey((X509 *)x);
                                  EVP_PKEY_copy_parameters
                                            ((EVP_PKEY *)pXVar37,(EVP_PKEY *)local_2a8);
                                  EVP_PKEY_save_parameters((EVP_PKEY *)pXVar37,1);
                                  EVP_PKEY_free((EVP_PKEY *)pXVar37);
                                  pXVar17 = X509_get_subject_name((X509 *)x);
                                  iVar8 = X509_set_issuer_name((X509 *)x,pXVar17);
                                  if ((((iVar8 != 0) &&
                                       (pAVar23 = X509_gmtime_adj(((X509_VAL *)x->ctx->verify)->
                                                                  notBefore,0),
                                       pAVar23 != (ASN1_TIME *)0x0)) &&
                                      (pAVar23 = X509_gmtime_adj(((X509_VAL *)x->ctx->verify)->
                                                                 notAfter,(long)(X509_STORE_CTX *)
                                                                                ((int)local_2ac *
                                                                                0x15180)),
                                      pAVar23 != (ASN1_TIME *)0x0)) &&
                                     (iVar8 = X509_set_pubkey((X509 *)x,(EVP_PKEY *)local_2a8),
                                     iVar8 != 0)) {
                                    if (bVar5) {
                                      while (iVar8 = X509_get_ext_count((X509 *)x), 0 < iVar8) {
                                        X509_delete_ext((X509 *)x,0);
                                      }
                                    }
                                    if (local_2ec != (X509_STORE_CTX *)0x0) {
                                      X509_set_version((X509 *)x,2);
                                      X509V3_set_ctx((X509V3_CTX *)&local_1e8,(X509 *)x,(X509 *)x,
                                                     (X509_REQ *)0x0,(X509_CRL *)0x0,0);
                                      X509V3_set_nconf((X509V3_CTX *)&local_1e8,(CONF *)local_2ec);
                                      iVar8 = X509V3_EXT_add_nconf
                                                        ((CONF *)local_2ec,(X509V3_CTX *)&local_1e8,
                                                         (char *)local_2c4,(X509 *)x);
                                      pXVar37 = local_2ec;
                                      if (iVar8 == 0) goto LAB_08063de9;
                                    }
                                    pcVar35 = (char *)local_2a8;
                                    pXVar36 = local_2bc;
                                    iVar8 = X509_sign((X509 *)x,(EVP_PKEY *)local_2a8,
                                                      (EVP_MD *)local_2bc);
                                    pXVar18 = extraout_ECX_06;
                                    pcVar27 = (char *)local_2a8;
                                    if (iVar8 != 0) goto LAB_08063bfd;
                                  }
LAB_08063de9:
                                  uVar31 = 1;
                                  ERR_print_errors(bio_err);
                                }
                                goto LAB_08063163;
                              }
                              if (local_2b4 == local_2cc) {
                                BIO_printf(bio_err,"Getting CA Private Key\n",pXVar18,pXVar18);
                                if ((local_2a0 != (X509_STORE_CTX *)0x0) &&
                                   (local_304 = (EVP_PKEY *)
                                                load_key(bio_err,local_2a0,local_2c8,0,local_210,
                                                         uVar31,"CA Private Key",extraout_EDX_01),
                                   local_304 == (EVP_PKEY *)0x0)) goto LAB_08063e8b;
                                if (!bVar3) {
                    /* WARNING: Subroutine does not return */
                                  __assert_fail("need_rand","x509.c",0x3d6,__PRETTY_FUNCTION___16775
                                               );
                                }
                                pcVar27 = (char *)local_2fc;
                                to = X509_get_pubkey((X509 *)local_2fc);
                                EVP_PKEY_copy_parameters(to,local_304);
                                EVP_PKEY_free(to);
                                iVar8 = X509_STORE_CTX_init(&local_1e8,local_308,(X509 *)x,
                                                            (stack_st_X509 *)0x0);
                                if (iVar8 == 0) {
                                  pXVar37 = (X509_STORE_CTX *)0x0;
                                  BIO_printf(bio_err,"Error initialising X509 store\n",to,to);
LAB_0806452e:
                                  X509_STORE_CTX_cleanup(&local_1e8);
                                  ERR_print_errors(bio_err);
                                  if (local_2f0 != (X509_STORE_CTX *)0x0) goto LAB_08063e8b;
                                }
                                else {
                                  pXVar37 = local_2f0;
                                  if (local_2f0 != (X509_STORE_CTX *)0x0) {
LAB_080644c0:
                                    X509_STORE_CTX_set_cert(&local_1e8,(X509 *)x);
                                    X509_STORE_CTX_set_flags(&local_1e8,0x4000);
                                    if ((reqfile != 0) ||
                                       (iVar8 = X509_verify_cert(&local_1e8), 0 < iVar8)) {
                                      iVar8 = X509_check_private_key((X509 *)local_2fc,local_304);
                                      if (iVar8 == 0) {
                                        BIO_printf(bio_err,
                                                  "CA certificate and CA private key do not match\n"
                                                  ,0,0);
                                      }
                                      else {
                                        pXVar17 = X509_get_subject_name((X509 *)local_2fc);
                                        iVar8 = X509_set_issuer_name((X509 *)x,pXVar17);
                                        if (((iVar8 != 0) &&
                                            (iVar8 = X509_set_serialNumber
                                                               ((X509 *)x,(ASN1_INTEGER *)pXVar37),
                                            iVar8 != 0)) &&
                                           (pAVar23 = X509_gmtime_adj(((X509_VAL *)x->ctx->verify)->
                                                                      notBefore,0),
                                           pAVar23 != (ASN1_TIME *)0x0)) {
                                          pXVar36 = (X509_STORE_CTX *)0x0;
                                          pcVar35 = (char *)local_2ac;
                                          pXVar11 = (X509_STORE_CTX *)
                                                    X509_time_adj_ex(((X509_VAL *)x->ctx->verify)->
                                                                     notAfter,(int)local_2ac,0,
                                                                     (time_t *)0x0);
                                          if (pXVar11 != (X509_STORE_CTX *)0x0) {
                                            if (bVar5) {
                                              while (pXVar11 = (X509_STORE_CTX *)
                                                               X509_get_ext_count((X509 *)x),
                                                    0 < (int)pXVar11) {
                                                pcVar35 = (char *)0x0;
                                                pXVar36 = extraout_ECX_39;
                                                X509_delete_ext((X509 *)x,0);
                                              }
                                            }
                                            if (local_2ec != (X509_STORE_CTX *)0x0) {
                                              X509_set_version((X509 *)x,2);
                                              X509V3_set_ctx(&local_204,(X509 *)local_2fc,(X509 *)x,
                                                             (X509_REQ *)0x0,(X509_CRL *)0x0,0);
                                              pcVar35 = (char *)local_2ec;
                                              X509V3_set_nconf(&local_204,(CONF *)local_2ec);
                                              iVar8 = X509V3_EXT_add_nconf
                                                                ((CONF *)local_2ec,&local_204,
                                                                 (char *)local_2c4,(X509 *)x);
                                              pcVar27 = (char *)local_2ec;
                                              pXVar36 = pXVar11;
                                              if (iVar8 == 0) goto LAB_0806452e;
                                            }
                                            iVar8 = do_X509_sign(bio_err,x,local_304,local_2bc,
                                                                 local_2f4);
                                            if (iVar8 != 0) {
                                              X509_STORE_CTX_cleanup(&local_1e8);
                                              pXVar18 = extraout_ECX_37;
                                              if (local_2f0 == (X509_STORE_CTX *)0x0) {
                                                ASN1_INTEGER_free((ASN1_INTEGER *)pXVar37);
                                                pXVar18 = extraout_ECX_38;
                                              }
                                              goto LAB_08063bfd;
                                            }
                                          }
                                        }
                                      }
                                    }
                                    goto LAB_0806452e;
                                  }
                                  local_204.flags = 0;
                                  if (local_29c == (byte *)0x0) {
                                    uVar24 = 0xffffffff;
                                    pXVar36 = local_2b8;
                                    do {
                                      if (uVar24 == 0) break;
                                      uVar24 = uVar24 - 1;
                                      ppXVar7 = &pXVar36->ctx;
                                      pXVar36 = (X509_STORE_CTX *)
                                                ((int)pXVar36 + (uint)bVar34 * -2 + 1);
                                    } while (*(byte *)ppXVar7 != 0);
                                    sVar21 = ~uVar24 + 5;
                                    pcVar27 = (char *)CRYPTO_malloc(sVar21,"x509.c",0x45d);
                                    uVar15 = extraout_EDX_04;
                                    if ((X509_STORE_CTX *)pcVar27 == (X509_STORE_CTX *)0x0)
                                    goto LAB_08064f2c;
                                    BUF_strlcpy(pcVar27,(char *)local_2b8,sVar21);
                                    for (pXVar36 = (X509_STORE_CTX *)pcVar27;
                                        *(byte *)&pXVar36->ctx != 0;
                                        pXVar36 = (X509_STORE_CTX *)((int)&pXVar36->ctx + 1)) {
                                      if (*(byte *)&pXVar36->ctx == 0x2e) {
                                        *(byte *)&pXVar36->ctx = 0;
                                        break;
                                      }
                                    }
                                    sVar21 = BUF_strlcat(pcVar27,".srl",sVar21);
LAB_08064e93:
                                    pBVar22 = (BIGNUM *)load_serial(pcVar27,local_248,0,sVar21);
                                    if (pBVar22 != (BIGNUM *)0x0) {
                                      iVar8 = BN_add_word(pBVar22,1);
                                      if (iVar8 == 0) {
                                        BIO_printf(bio_err,"add_word failure\n",extraout_ECX_36,
                                                   extraout_ECX_36);
                                      }
                                      else {
                                        save_serial(pcVar27,0,pBVar22,&local_204);
                                      }
                                    }
                                    CRYPTO_free(pcVar27);
                                  }
                                  else {
                                    uVar24 = 0xffffffff;
                                    pbVar30 = local_29c;
                                    do {
                                      if (uVar24 == 0) break;
                                      uVar24 = uVar24 - 1;
                                      bVar1 = *pbVar30;
                                      pbVar30 = pbVar30 + (uint)bVar34 * -2 + 1;
                                    } while (bVar1 != 0);
                                    pcVar27 = (char *)CRYPTO_malloc(~uVar24,"x509.c",0x45d);
                                    uVar15 = extraout_EDX_03;
                                    if ((X509_STORE_CTX *)pcVar27 != (X509_STORE_CTX *)0x0) {
                                      sVar21 = BUF_strlcpy(pcVar27,(char *)local_29c,~uVar24);
                                      goto LAB_08064e93;
                                    }
LAB_08064f2c:
                                    pBVar22 = (BIGNUM *)0x0;
                                    BIO_printf(bio_err,"out of mem\n",uVar15,uVar15);
                                  }
                                  BN_free(pBVar22);
                                  pXVar37 = (X509_STORE_CTX *)local_204.flags;
                                  if ((X509_STORE_CTX *)local_204.flags != (X509_STORE_CTX *)0x0)
                                  goto LAB_080644c0;
                                  X509_STORE_CTX_cleanup(&local_1e8);
                                  ERR_print_errors(bio_err);
                                }
                                uVar31 = 1;
                                ASN1_INTEGER_free((ASN1_INTEGER *)pXVar37);
                                goto LAB_08063163;
                              }
                              if (local_268 != local_2cc) {
                                if (local_250 == local_2cc) {
                                  pcVar35 = (char *)x;
                                  pXVar36 = (X509_STORE_CTX *)pcVar27;
                                  X509_ocspid_print((BIO *)pXVar28,(X509 *)x);
                                  pXVar18 = extraout_ECX_24;
                                }
                                goto LAB_08063bfd;
                              }
                              iVar8 = BIO_printf(bio_err,"Getting request Private Key\n",pXVar13,
                                                 pXVar13);
                              if (local_2a4 == (byte *)0x0) {
                                uVar31 = 1;
                                BIO_printf(bio_err,"no request key file specified\n",iVar8,iVar8);
                                goto LAB_08063163;
                              }
                              pXVar37 = (X509_STORE_CTX *)
                                        load_key(bio_err,local_2a4,local_2d0,0,local_210,uVar31,
                                                 "request key",pXVar11);
                              if (pXVar37 == (X509_STORE_CTX *)0x0) goto LAB_08063e8b;
                              BIO_printf(bio_err,"Generating certificate request\n",extraout_ECX_25,
                                         extraout_ECX_25);
                              pcVar35 = (char *)pXVar37;
                              pXVar11 = local_2bc;
                              local_300 = (X509_STORE_CTX *)
                                          X509_to_X509_REQ((X509 *)x,(EVP_PKEY *)pXVar37,
                                                           (EVP_MD *)local_2bc);
                              pXVar36 = local_300;
                              EVP_PKEY_free((EVP_PKEY *)pXVar37);
                              if (local_300 == (X509_STORE_CTX *)0x0) goto LAB_08063de9;
                              pcVar27 = (char *)local_300;
                              if (local_2c0 == (X509_STORE_CTX *)0x0) {
                                X509_REQ_print((BIO *)pXVar28,(X509_REQ *)local_300);
                                pcVar35 = (char *)local_300;
                                PEM_write_bio_X509_REQ((BIO *)pXVar28,(X509_REQ *)local_300);
                                local_2c0 = (X509_STORE_CTX *)0x1;
                                pXVar18 = extraout_ECX_27;
                                pXVar37 = pXVar28;
                              }
                              else {
                                local_2c0 = (X509_STORE_CTX *)0x1;
                                pXVar18 = extraout_ECX_26;
                                pXVar36 = pXVar11;
                              }
                              goto LAB_08063bfd;
                            }
                            pcVar27 = "notAfter=";
                            pXVar11 = local_2e0;
                            BIO_puts((BIO *)local_2e0,"notAfter=");
                            pAVar23 = ((X509_VAL *)x->ctx->verify)->notAfter;
                            pXVar13 = pXVar18;
                          }
                          ASN1_TIME_print((BIO *)local_2e0,pAVar23);
                          pcVar35 = &DAT_081f11d3;
                          BIO_puts((BIO *)local_2e0,"\n");
                          pXVar18 = extraout_ECX_07;
                          pXVar37 = pXVar11;
                          pXVar36 = pXVar13;
                          goto LAB_08063bfd;
                        }
                        pcVar35 = (char *)x;
                        pXVar36 = local_20c;
                        X509_print_ex((BIO *)local_2e0,(X509 *)x,(ulong)local_20c,local_208);
                        pXVar18 = extraout_ECX_23;
                      }
                      goto LAB_08063bfd;
                    }
                    pXVar36 = (X509_STORE_CTX *)X509_issuer_name_hash_old((X509 *)x);
                  }
                  pcVar35 = "%08lx\n";
                  BIO_printf((BIO *)local_2e0,"%08lx\n");
                  pXVar18 = extraout_ECX_10;
                }
              }
LAB_08063bfd:
              pXVar13 = (X509_STORE_CTX *)((int)&local_2cc->ctx + 1);
              pXVar11 = pXVar37;
              local_2cc = pXVar13;
              if ((int)local_2d4 < (int)pXVar13) goto LAB_08063925;
              goto LAB_08063c10;
            }
            local_300 = (X509_STORE_CTX *)0x0;
            local_304 = (EVP_PKEY *)0x0;
            local_2a8 = (X509_STORE_CTX *)0x0;
LAB_08063925:
            if (bVar4) {
              tVar14 = time((time_t *)0x0);
              local_1e8.ctx = (X509_STORE *)(tVar14 + local_224);
              iVar8 = X509_cmp_time(((X509_VAL *)x->ctx->verify)->notAfter,(time_t *)&local_1e8);
              if (iVar8 < 0) {
                uVar31 = 1;
                BIO_printf((BIO *)pXVar28,"Certificate will expire\n",extraout_EDX_00,
                           extraout_EDX_00);
              }
              else {
                uVar31 = 0;
                BIO_printf((BIO *)pXVar28,"Certificate will not expire\n",iVar8,iVar8);
              }
            }
            else {
              uVar31 = 0;
              if (local_2c0 == (X509_STORE_CTX *)0x0) {
                if (local_2d8 == 1) {
                  iVar8 = i2d_X509_bio((BIO *)pXVar28,(X509 *)x);
                }
                else if (local_2d8 == 3) {
                  if (bVar6) {
                    iVar8 = PEM_write_bio_X509_AUX((BIO *)pXVar28,(X509 *)x);
                  }
                  else {
                    iVar8 = PEM_write_bio_X509((BIO *)pXVar28,(X509 *)x);
                  }
                }
                else {
                  if (local_2d8 != 4) {
                    uVar31 = 1;
                    BIO_printf(bio_err,"bad output format specified for outfile\n",pXVar13,pXVar13);
                    goto LAB_08063163;
                  }
                  local_204.flags = (int)&local_1e8;
                  local_1e8.cert = (X509 *)0x822b14d;
                  local_1e8.ctx = (X509_STORE *)0xb;
                  local_204.issuer_cert = (X509 *)x;
                  iVar8 = ASN1_item_i2d_bio((ASN1_ITEM *)NETSCAPE_X509_it,(BIO *)pXVar28,&local_204)
                  ;
                }
                uVar31 = 0;
                if (iVar8 == 0) {
                  pXVar37 = (X509_STORE_CTX *)0x0;
                  pcVar35 = "unable to write certificate\n";
LAB_08064316:
                  uVar31 = 1;
                  BIO_printf(bio_err,pcVar35,pXVar37,pXVar37);
                  ERR_print_errors(bio_err);
                }
              }
            }
          }
        }
        else {
          if (((uint)local_270 | (uint)local_2b4) == 0) {
            BIO_printf(bio_err,"We need a private key to sign with\n",pXVar11,pXVar11);
            goto LAB_08063138;
          }
          pBVar9 = BIO_s_file();
          x = (X509_STORE_CTX *)BIO_new(pBVar9);
          if (x == (X509_STORE_CTX *)0x0) {
            ERR_print_errors(bio_err);
            goto LAB_0806478f;
          }
          if (local_2fc == (X509_STORE_CTX *)0x0) {
            BIO_ctrl((BIO *)x,0x6a,0x10,stdin);
          }
          else {
            lVar10 = BIO_ctrl((BIO *)x,0x6c,3,local_2fc);
            if (lVar10 < 1) {
              perror((char *)local_2fc);
              BIO_free((BIO *)x);
              goto LAB_08063138;
            }
          }
          pXVar11 = (X509_STORE_CTX *)
                    PEM_read_bio_X509_REQ((BIO *)x,(X509_REQ **)0x0,(undefined1 *)0x0,(void *)0x0);
          BIO_free((BIO *)x);
          local_2f8 = pXVar11;
          if (pXVar11 == (X509_STORE_CTX *)0x0) {
            ERR_print_errors(bio_err);
          }
          else {
            if ((((pXVar11->ctx != (X509_STORE *)0x0) &&
                 (pXVar17 = (X509_NAME *)pXVar11->ctx->verify_cb, pXVar17 != (X509_NAME *)0x0)) &&
                (iVar8 = pXVar17->modified, iVar8 != 0)) && (*(int *)(iVar8 + 8) != 0)) {
              x = (X509_STORE_CTX *)X509_REQ_get_pubkey((X509_REQ *)pXVar11);
              pXVar28 = local_2f0;
              if (x == (X509_STORE_CTX *)0x0) {
                BIO_printf(bio_err,"error unpacking public key\n",extraout_EDX,extraout_EDX);
              }
              else {
                iVar12 = X509_REQ_verify((X509_REQ *)pXVar11,(EVP_PKEY *)x);
                iVar8 = iVar12;
                EVP_PKEY_free((EVP_PKEY *)x);
                if (iVar12 < 0) {
                  BIO_printf(bio_err,"Signature verification error\n",iVar8,iVar8);
                  ERR_print_errors(bio_err);
                  goto LAB_080637c8;
                }
                if (iVar12 == 0) {
                  pcVar35 = "Signature did not match the certificate request\n";
                  iVar12 = iVar8;
                  goto LAB_080637bd;
                }
                BIO_printf(bio_err,"Signature ok\n",iVar8,iVar8);
                print_name(bio_err,"subject=",(X509_VAL *)pXVar11->ctx->verify,local_20c);
                x = (X509_STORE_CTX *)X509_new();
                if (x != (X509_STORE_CTX *)0x0) {
                  if (local_2f0 == (X509_STORE_CTX *)0x0) {
                    pXVar28 = (X509_STORE_CTX *)ASN1_INTEGER_new();
                    if (pXVar28 == (X509_STORE_CTX *)0x0) {
                      local_2f0 = (X509_STORE_CTX *)0x0;
                      pXVar28 = local_2f0;
                    }
                    else {
                      iVar8 = rand_serial(0,pXVar28,pXVar28,pXVar28);
                      if ((iVar8 != 0) &&
                         (iVar8 = X509_set_serialNumber((X509 *)x,(ASN1_INTEGER *)pXVar28),
                         iVar8 != 0)) {
                        ASN1_INTEGER_free((ASN1_INTEGER *)pXVar28);
                        goto LAB_080648ab;
                      }
                    }
                  }
                  else {
                    iVar8 = X509_set_serialNumber((X509 *)x,(ASN1_INTEGER *)local_2f0);
                    if (iVar8 != 0) {
LAB_080648ab:
                      iVar8 = X509_set_issuer_name((X509 *)x,(X509_NAME *)pXVar11->ctx->verify);
                      pXVar28 = local_2f0;
                      if ((iVar8 != 0) &&
                         (pXVar36 = (X509_STORE_CTX *)
                                    X509_set_subject_name
                                              ((X509 *)x,(X509_NAME *)pXVar11->ctx->verify),
                         pXVar36 != (X509_STORE_CTX *)0x0)) {
                        X509_gmtime_adj(((X509_VAL *)x->ctx->verify)->notBefore,0);
                        X509_time_adj_ex(((X509_VAL *)x->ctx->verify)->notAfter,(int)local_2ac,0,
                                         (time_t *)0x0);
                        pXVar18 = (X509_STORE_CTX *)X509_REQ_get_pubkey((X509_REQ *)pXVar11);
                        pcVar35 = (char *)pXVar18;
                        pXVar28 = (X509_STORE_CTX *)X509_set_pubkey((X509 *)x,(EVP_PKEY *)pXVar18);
                        EVP_PKEY_free((EVP_PKEY *)pXVar18);
                        pXVar18 = extraout_ECX_32;
                        goto LAB_0806382b;
                      }
                    }
                  }
                }
              }
              local_2f0 = pXVar28;
              local_300 = (X509_STORE_CTX *)0x0;
              pXVar28 = (X509_STORE_CTX *)0x0;
              local_304 = (EVP_PKEY *)0x0;
              local_2a8 = (X509_STORE_CTX *)0x0;
              local_2fc = (X509_STORE_CTX *)0x0;
              uVar31 = 1;
              goto LAB_08063163;
            }
            iVar8 = extraout_ECX;
            iVar12 = extraout_ECX;
            BIO_printf(bio_err,"The certificate request appears to corrupted\n",extraout_ECX,
                       extraout_ECX);
            pcVar35 = "It does not contain a public key\n";
LAB_080637bd:
            BIO_printf(bio_err,pcVar35,iVar8,iVar12);
          }
LAB_080637c8:
          local_300 = (X509_STORE_CTX *)0x0;
          pXVar28 = (X509_STORE_CTX *)0x0;
          local_304 = (EVP_PKEY *)0x0;
          local_2a8 = (X509_STORE_CTX *)0x0;
          local_2fc = (X509_STORE_CTX *)0x0;
          x = (X509_STORE_CTX *)0x0;
          uVar31 = 1;
        }
      }
LAB_08063163:
      if (bVar3) {
        app_RAND_write_file(0,bio_err);
      }
      goto LAB_08062bed;
    }
  }
  local_2e4 = (X509_STORE_CTX *)0x0;
  local_2e8 = (_STACK *)0x0;
  local_2ec = (X509_STORE_CTX *)0x0;
  local_300 = (X509_STORE_CTX *)0x0;
  pXVar28 = (X509_STORE_CTX *)0x0;
  local_2f0 = (X509_STORE_CTX *)0x0;
  local_304 = (EVP_PKEY *)0x0;
  local_2a8 = (X509_STORE_CTX *)0x0;
  local_2f4 = (_STACK *)0x0;
  local_2fc = (X509_STORE_CTX *)0x0;
  x = (X509_STORE_CTX *)0x0;
  local_2f8 = (X509_STORE_CTX *)0x0;
  uVar31 = 1;
LAB_08062bed:
  OBJ_cleanup();
  NCONF_free((CONF *)local_2ec);
  BIO_free_all((BIO *)pXVar28);
  BIO_free_all((BIO *)local_2e0);
  X509_STORE_free(local_308);
  X509_REQ_free((X509_REQ *)local_2f8);
  X509_free((X509 *)x);
  X509_free((X509 *)local_2fc);
  EVP_PKEY_free((EVP_PKEY *)local_2a8);
  EVP_PKEY_free(local_304);
  if (local_2f4 != (_STACK *)0x0) {
    sk_free(local_2f4);
  }
  X509_REQ_free((X509_REQ *)local_300);
  ASN1_INTEGER_free((ASN1_INTEGER *)local_2f0);
  sk_pop_free(local_2e8,ASN1_OBJECT_free);
  sk_pop_free((_STACK *)local_2e4,ASN1_OBJECT_free);
  if (local_210 != (void *)0x0) {
    CRYPTO_free(local_210);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar31;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
