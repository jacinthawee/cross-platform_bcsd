
/* WARNING: Type propagation algorithm not settling */

int smime_main(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  EVP_CIPHER *pEVar6;
  BIO_METHOD *type;
  void *pvVar7;
  EVP_PKEY *pkey;
  PKCS7_SIGNER_INFO *pPVar8;
  int iVar9;
  _STACK *p_Var10;
  BIO *pBVar11;
  int iVar12;
  undefined4 extraout_EDX;
  byte **ppbVar13;
  uint uVar14;
  X509 *pXVar15;
  PKCS7 *p7;
  uint uVar16;
  byte *pbVar17;
  EVP_PKEY *pkey_00;
  byte *pbVar18;
  int in_GS_OFFSET;
  bool bVar20;
  bool bVar21;
  byte bVar22;
  char *pcVar23;
  uint local_ac;
  _STACK *local_a8;
  _STACK *local_a4;
  BIO *local_a0;
  X509_STORE *local_9c;
  BIO *local_98;
  X509 *local_94;
  EVP_CIPHER *local_90;
  EVP_CIPHER *local_8c;
  EVP_CIPHER *local_88;
  EVP_CIPHER *local_80;
  undefined4 local_7c;
  EVP_MD *local_78;
  int local_74;
  int local_70;
  char *local_6c;
  EVP_CIPHER *local_68;
  EVP_CIPHER *local_60;
  byte *local_5c;
  EVP_CIPHER *local_58;
  EVP_CIPHER *local_54;
  EVP_CIPHER *local_50;
  EVP_CIPHER *local_4c;
  EVP_CIPHER *local_48;
  char *local_44;
  char *local_40;
  byte **local_34;
  BIO *local_30;
  int local_2c;
  void *local_28;
  X509_VERIFY_PARAM *local_24;
  int local_20;
  byte *pbVar19;
  
  bVar22 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30 = (BIO *)0x0;
  local_2c = 0;
  local_28 = (void *)0x0;
  local_24 = (X509_VERIFY_PARAM *)0x0;
  local_34 = (byte **)(param_2 + 4);
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar4 = load_config(bio_err,0);
  if (iVar4 == 0) {
    local_9c = (X509_STORE *)0x0;
    pkey_00 = (EVP_PKEY *)0x0;
    local_8c = (EVP_CIPHER *)0x0;
    pXVar15 = (X509 *)0x0;
    local_94 = (X509 *)0x0;
    iVar4 = 1;
    local_a8 = (_STACK *)0x0;
    p7 = (PKCS7 *)0x0;
    local_90 = (EVP_CIPHER *)0x0;
    local_98 = (BIO *)0x0;
    local_a0 = (BIO *)0x0;
    local_a4 = (_STACK *)0x0;
  }
  else {
    local_8c = (EVP_CIPHER *)0x0;
    local_7c = 3;
    local_70 = 6;
    local_74 = 6;
    local_78 = (EVP_MD *)0x0;
    bVar3 = false;
    bVar2 = false;
    local_5c = (byte *)0x0;
    local_90 = (EVP_CIPHER *)0x0;
    local_48 = (EVP_CIPHER *)0x0;
    local_4c = (EVP_CIPHER *)0x0;
    local_50 = (EVP_CIPHER *)0x0;
    local_54 = (EVP_CIPHER *)0x0;
    local_58 = (EVP_CIPHER *)0x0;
    local_80 = (EVP_CIPHER *)0x40;
    local_9c = (X509_STORE *)0x0;
    local_60 = (EVP_CIPHER *)0x0;
    local_a0 = (BIO *)0x0;
    local_94 = (X509 *)0x0;
    local_a4 = (_STACK *)0x0;
    local_a8 = (_STACK *)0x0;
    local_98 = (BIO *)0x0;
    local_88 = (EVP_CIPHER *)0x0;
    local_68 = (EVP_CIPHER *)0x0;
    local_6c = (char *)0x0;
    local_ac = 0;
LAB_08086a5b:
    iVar4 = local_2c;
    if (local_2c == 0) {
LAB_08086a68:
      ppbVar13 = local_34;
      pbVar1 = *local_34;
      if (pbVar1 == (byte *)0x0) goto LAB_08086b46;
      bVar20 = *pbVar1 < 0x2d;
      bVar21 = *pbVar1 == 0x2d;
      if (!bVar21) goto LAB_08086b46;
      iVar4 = 9;
      pbVar17 = pbVar1;
      pbVar19 = (byte *)"-encrypt";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar20 = *pbVar17 < *pbVar19;
        bVar21 = *pbVar17 == *pbVar19;
        pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
        pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      iVar4 = (int)(char)((!bVar20 && !bVar21) - bVar20);
      bVar20 = false;
      bVar21 = iVar4 == 0;
      if (bVar21) {
        local_ac = 0x11;
        local_34 = ppbVar13;
      }
      else {
        iVar4 = 9;
        pbVar17 = pbVar1;
        pbVar19 = (byte *)"-decrypt";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar20 = *pbVar17 < *pbVar19;
          bVar21 = *pbVar17 == *pbVar19;
          pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
          pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
        } while (bVar21);
        iVar4 = (int)(char)((!bVar20 && !bVar21) - bVar20);
        bVar20 = false;
        bVar21 = iVar4 == 0;
        if (bVar21) {
          local_ac = 0x22;
          local_34 = ppbVar13;
        }
        else {
          iVar4 = 6;
          pbVar17 = pbVar1;
          pbVar19 = (byte *)"-sign";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar20 = *pbVar17 < *pbVar19;
            bVar21 = *pbVar17 == *pbVar19;
            pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
            pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
          } while (bVar21);
          iVar4 = (int)(char)((!bVar20 && !bVar21) - bVar20);
          bVar20 = false;
          bVar21 = iVar4 == 0;
          if (bVar21) {
            local_ac = 0x53;
            local_34 = ppbVar13;
          }
          else {
            iVar4 = 8;
            pbVar17 = pbVar1;
            pbVar19 = (byte *)"-resign";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar20 = *pbVar17 < *pbVar19;
              bVar21 = *pbVar17 == *pbVar19;
              pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
              pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
            } while (bVar21);
            iVar4 = (int)(char)((!bVar20 && !bVar21) - bVar20);
            bVar20 = false;
            bVar21 = iVar4 == 0;
            if (bVar21) {
              local_ac = 0x76;
              local_34 = ppbVar13;
            }
            else {
              iVar4 = 8;
              pbVar17 = pbVar1;
              pbVar19 = (byte *)"-verify";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar20 = *pbVar17 < *pbVar19;
                bVar21 = *pbVar17 == *pbVar19;
                pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
              } while (bVar21);
              iVar4 = (int)(char)((!bVar20 && !bVar21) - bVar20);
              bVar20 = false;
              bVar21 = iVar4 == 0;
              if (bVar21) {
                local_ac = 0x24;
                local_34 = ppbVar13;
              }
              else {
                iVar4 = 8;
                pbVar17 = pbVar1;
                pbVar19 = (byte *)"-pk7out";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar20 = *pbVar17 < *pbVar19;
                  bVar21 = *pbVar17 == *pbVar19;
                  pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                  pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                } while (bVar21);
                iVar4 = (int)(char)((!bVar20 && !bVar21) - bVar20);
                bVar20 = false;
                bVar21 = iVar4 == 0;
                if (bVar21) {
                  local_ac = 0x35;
                  local_34 = ppbVar13;
                }
                else {
                  iVar4 = 6;
                  pbVar17 = pbVar1;
                  pbVar19 = &DAT_081f25ea;
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar20 = *pbVar17 < *pbVar19;
                    bVar21 = *pbVar17 == *pbVar19;
                    pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                    pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                  } while (bVar21);
                  if (bVar21) {
                    local_9c = (X509_STORE *)EVP_des_ede3_cbc();
                    iVar4 = local_2c;
                  }
                  else {
                    iVar4 = 5;
                    pbVar17 = pbVar1;
                    pbVar19 = &DAT_081f25e5;
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar20 = *pbVar17 < *pbVar19;
                      bVar21 = *pbVar17 == *pbVar19;
                      pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                      pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                    } while (bVar21);
                    if (bVar21) {
                      local_9c = (X509_STORE *)EVP_des_cbc();
                      iVar4 = local_2c;
                    }
                    else {
                      iVar4 = 6;
                      pbVar17 = pbVar1;
                      pbVar19 = (byte *)"-seed";
                      do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar20 = *pbVar17 < *pbVar19;
                        bVar21 = *pbVar17 == *pbVar19;
                        pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                        pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                      } while (bVar21);
                      if (bVar21) {
                        local_9c = (X509_STORE *)EVP_seed_cbc();
                        iVar4 = local_2c;
                      }
                      else {
                        iVar4 = 8;
                        pbVar17 = pbVar1;
                        pbVar19 = (byte *)"-rc2-40";
                        do {
                          if (iVar4 == 0) break;
                          iVar4 = iVar4 + -1;
                          bVar20 = *pbVar17 < *pbVar19;
                          bVar21 = *pbVar17 == *pbVar19;
                          pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                          pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                        } while (bVar21);
                        if (bVar21) {
                          local_9c = (X509_STORE *)EVP_rc2_40_cbc();
                          iVar4 = local_2c;
                        }
                        else {
                          iVar4 = 9;
                          pbVar17 = pbVar1;
                          pbVar19 = (byte *)"-rc2-128";
                          do {
                            if (iVar4 == 0) break;
                            iVar4 = iVar4 + -1;
                            bVar20 = *pbVar17 < *pbVar19;
                            bVar21 = *pbVar17 == *pbVar19;
                            pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                            pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                          } while (bVar21);
                          if (bVar21) {
                            local_9c = (X509_STORE *)EVP_rc2_cbc();
                            iVar4 = local_2c;
                          }
                          else {
                            iVar4 = 8;
                            pbVar17 = pbVar1;
                            pbVar19 = (byte *)"-rc2-64";
                            do {
                              if (iVar4 == 0) break;
                              iVar4 = iVar4 + -1;
                              bVar20 = *pbVar17 < *pbVar19;
                              bVar21 = *pbVar17 == *pbVar19;
                              pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                              pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                            } while (bVar21);
                            if (bVar21) {
                              local_9c = (X509_STORE *)EVP_rc2_64_cbc();
                              iVar4 = local_2c;
                            }
                            else {
                              iVar4 = 8;
                              pbVar17 = pbVar1;
                              pbVar19 = &DAT_081f25fc;
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar20 = *pbVar17 < *pbVar19;
                                bVar21 = *pbVar17 == *pbVar19;
                                pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                                pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                              } while (bVar21);
                              if (bVar21) {
                                local_9c = (X509_STORE *)EVP_aes_128_cbc();
                                iVar4 = local_2c;
                              }
                              else {
                                iVar4 = 8;
                                pbVar17 = pbVar1;
                                pbVar19 = &DAT_081f2604;
                                do {
                                  if (iVar4 == 0) break;
                                  iVar4 = iVar4 + -1;
                                  bVar20 = *pbVar17 < *pbVar19;
                                  bVar21 = *pbVar17 == *pbVar19;
                                  pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                                  pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                                } while (bVar21);
                                if (bVar21) {
                                  local_9c = (X509_STORE *)EVP_aes_192_cbc();
                                  iVar4 = local_2c;
                                }
                                else {
                                  iVar4 = 8;
                                  pbVar17 = pbVar1;
                                  pbVar19 = &DAT_081f260c;
                                  do {
                                    if (iVar4 == 0) break;
                                    iVar4 = iVar4 + -1;
                                    bVar20 = *pbVar17 < *pbVar19;
                                    bVar21 = *pbVar17 == *pbVar19;
                                    pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                                    pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                                  } while (bVar21);
                                  if (bVar21) {
                                    local_9c = (X509_STORE *)EVP_aes_256_cbc();
                                    iVar4 = local_2c;
                                  }
                                  else {
                                    iVar4 = 0xd;
                                    pbVar17 = pbVar1;
                                    pbVar19 = (byte *)"-camellia128";
                                    do {
                                      if (iVar4 == 0) break;
                                      iVar4 = iVar4 + -1;
                                      bVar20 = *pbVar17 < *pbVar19;
                                      bVar21 = *pbVar17 == *pbVar19;
                                      pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                                      pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                                    } while (bVar21);
                                    if (bVar21) {
                                      local_9c = (X509_STORE *)EVP_camellia_128_cbc();
                                      iVar4 = local_2c;
                                    }
                                    else {
                                      iVar4 = 0xd;
                                      pbVar17 = pbVar1;
                                      pbVar19 = (byte *)"-camellia192";
                                      do {
                                        if (iVar4 == 0) break;
                                        iVar4 = iVar4 + -1;
                                        bVar20 = *pbVar17 < *pbVar19;
                                        bVar21 = *pbVar17 == *pbVar19;
                                        pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                                        pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                                      } while (bVar21);
                                      if (bVar21) {
                                        local_9c = (X509_STORE *)EVP_camellia_192_cbc();
                                        iVar4 = local_2c;
                                      }
                                      else {
                                        iVar4 = 0xd;
                                        pbVar17 = pbVar1;
                                        pbVar19 = (byte *)"-camellia256";
                                        do {
                                          if (iVar4 == 0) break;
                                          iVar4 = iVar4 + -1;
                                          bVar20 = *pbVar17 < *pbVar19;
                                          bVar21 = *pbVar17 == *pbVar19;
                                          pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                                          pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                                        } while (bVar21);
                                        if (bVar21) {
                                          local_9c = (X509_STORE *)EVP_camellia_256_cbc();
                                          iVar4 = local_2c;
                                        }
                                        else {
                                          iVar4 = 6;
                                          pbVar17 = pbVar1;
                                          pbVar19 = (byte *)"-text";
                                          do {
                                            if (iVar4 == 0) break;
                                            iVar4 = iVar4 + -1;
                                            bVar20 = *pbVar17 < *pbVar19;
                                            bVar21 = *pbVar17 == *pbVar19;
                                            pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                                            pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                                          } while (bVar21);
                                          iVar4 = (int)(char)((!bVar20 && !bVar21) - bVar20);
                                          bVar20 = false;
                                          bVar21 = iVar4 == 0;
                                          if (bVar21) {
                                            local_80 = (EVP_CIPHER *)((uint)local_80 | 1);
                                            local_34 = ppbVar13;
                                          }
                                          else {
                                            iVar4 = 10;
                                            pbVar17 = pbVar1;
                                            pbVar19 = (byte *)"-nointern";
                                            do {
                                              if (iVar4 == 0) break;
                                              iVar4 = iVar4 + -1;
                                              bVar20 = *pbVar17 < *pbVar19;
                                              bVar21 = *pbVar17 == *pbVar19;
                                              pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                                              pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                                            } while (bVar21);
                                            iVar4 = (int)(char)((!bVar20 && !bVar21) - bVar20);
                                            bVar20 = false;
                                            bVar21 = iVar4 == 0;
                                            if (bVar21) {
                                              local_80 = (EVP_CIPHER *)((uint)local_80 | 0x10);
                                              local_34 = ppbVar13;
                                            }
                                            else {
                                              iVar4 = 10;
                                              pbVar17 = pbVar1;
                                              pbVar19 = (byte *)"-noverify";
                                              do {
                                                pbVar18 = pbVar19;
                                                if (iVar4 == 0) break;
                                                iVar4 = iVar4 + -1;
                                                pbVar18 = pbVar19 + (uint)bVar22 * -2 + 1;
                                                bVar20 = *pbVar17 < *pbVar19;
                                                bVar21 = *pbVar17 == *pbVar19;
                                                pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                                                pbVar19 = pbVar18;
                                              } while (bVar21);
                                              iVar4 = (int)(char)((!bVar20 && !bVar21) - bVar20);
                                              if (iVar4 == 0) {
                                                local_80 = (EVP_CIPHER *)((uint)local_80 | 0x20);
                                                local_34 = ppbVar13;
                                              }
                                              else {
                                                iVar4 = strcmp((char *)pbVar1,"-nochain");
                                                if (iVar4 == 0) {
                                                  local_80 = (EVP_CIPHER *)((uint)local_80 | 8);
                                                  local_34 = ppbVar13;
                                                }
                                                else {
                                                  iVar4 = strcmp((char *)pbVar1,"-nocerts");
                                                  if (iVar4 == 0) {
                                                    local_80 = (EVP_CIPHER *)((uint)local_80 | 2);
                                                    local_34 = ppbVar13;
                                                  }
                                                  else {
                                                    iVar4 = strcmp((char *)pbVar1,"-noattr");
                                                    if (iVar4 == 0) {
                                                      local_80 = (EVP_CIPHER *)
                                                                 ((uint)local_80 | 0x100);
                                                      local_34 = ppbVar13;
                                                    }
                                                    else {
                                                      iVar4 = strcmp((char *)pbVar1,"-nodetach");
                                                      if (iVar4 == 0) {
                                                        local_80 = (EVP_CIPHER *)
                                                                   ((uint)local_80 & 0xffffffbf);
                                                        local_34 = ppbVar13;
                                                      }
                                                      else {
                                                        iVar4 = strcmp((char *)pbVar1,"-nosmimecap")
                                                        ;
                                                        if (iVar4 == 0) {
                                                          local_80 = (EVP_CIPHER *)
                                                                     ((uint)local_80 | 0x200);
                                                          local_34 = ppbVar13;
                                                        }
                                                        else {
                                                          iVar4 = strcmp((char *)pbVar1,"-binary");
                                                          if (iVar4 == 0) {
                                                            local_80 = (EVP_CIPHER *)
                                                                       ((uint)local_80 | 0x80);
                                                            local_34 = ppbVar13;
                                                          }
                                                          else {
                                                            iVar4 = strcmp((char *)pbVar1,"-nosigs")
                                                            ;
                                                            if (iVar4 == 0) {
                                                              local_80 = (EVP_CIPHER *)
                                                                         ((uint)local_80 | 4);
                                                              local_34 = ppbVar13;
                                                            }
                                                            else {
                                                              iVar4 = strcmp((char *)pbVar1,
                                                                             "-stream");
                                                              if ((iVar4 == 0) ||
                                                                 (iVar4 = strcmp((char *)pbVar1,
                                                                                 "-indef"),
                                                                 iVar4 == 0)) {
                                                                bVar3 = true;
                                                                local_34 = ppbVar13;
                                                              }
                                                              else {
                                                                iVar4 = strcmp((char *)pbVar1,
                                                                               "-noindef");
                                                                if (iVar4 == 0) {
                                                                  bVar3 = false;
                                                                  local_34 = ppbVar13;
                                                                }
                                                                else {
                                                                  iVar4 = strcmp((char *)pbVar1,
                                                                                 "-nooldmime");
                                                                  if (iVar4 == 0) {
                                                                    local_80 = (EVP_CIPHER *)
                                                                               ((uint)local_80 |
                                                                               0x400);
                                                                    local_34 = ppbVar13;
                                                                  }
                                                                  else {
                                                                    iVar4 = strcmp((char *)pbVar1,
                                                                                   "-crlfeol");
                                                                    if (iVar4 == 0) {
                                                                      local_80 = (EVP_CIPHER *)
                                                                                 ((uint)local_80 |
                                                                                 0x800);
                                                                      local_34 = ppbVar13;
                                                                    }
                                                                    else {
                                                                      iVar4 = strcmp((char *)pbVar1,
                                                                                     "-rand");
                                                                      if (iVar4 == 0) {
                                                                        local_5c = ppbVar13[1];
                                                                        if (local_5c == (byte *)0x0)
                                                                        goto LAB_08086ba4;
                                                                        bVar2 = true;
                                                                        local_34 = ppbVar13 + 1;
                                                                      }
                                                                      else {
                                                                        iVar4 = strcmp((char *)
                                                  pbVar1,"-engine");
                                                  if (iVar4 == 0) {
                                                    local_8c = (EVP_CIPHER *)ppbVar13[1];
                                                    pEVar6 = local_8c;
                                                  }
                                                  else {
                                                    iVar4 = strcmp((char *)pbVar1,"-passin");
                                                    if (iVar4 == 0) {
                                                      local_90 = (EVP_CIPHER *)ppbVar13[1];
                                                      pEVar6 = local_90;
                                                    }
                                                    else {
                                                      uVar14 = (uint)pbVar1[1];
                                                      if (((uVar14 == 0x74) && (pbVar1[2] == 0x6f))
                                                         && (pbVar1[3] == 0)) {
                                                        local_58 = (EVP_CIPHER *)ppbVar13[1];
                                                        pEVar6 = local_58;
joined_r0x080883b4:
                                                        if (pEVar6 != (EVP_CIPHER *)0x0) {
                                                          iVar4 = 0;
                                                          local_34 = ppbVar13 + 1;
                                                          goto LAB_08086b37;
                                                        }
                                                        goto LAB_08086ba4;
                                                      }
                                                      iVar4 = strcmp((char *)pbVar1,"-from");
                                                      if (iVar4 == 0) {
                                                        local_54 = (EVP_CIPHER *)ppbVar13[1];
                                                        pEVar6 = local_54;
                                                      }
                                                      else {
                                                        iVar4 = strcmp((char *)pbVar1,"-subject");
                                                        if (iVar4 == 0) {
                                                          local_50 = (EVP_CIPHER *)ppbVar13[1];
                                                          pEVar6 = local_50;
                                                        }
                                                        else {
                                                          iVar4 = strcmp((char *)pbVar1,"-signer");
                                                          if (iVar4 == 0) {
                                                            if (ppbVar13[1] == (byte *)0x0)
                                                            goto LAB_08086ba4;
                                                            if (local_88 != (EVP_CIPHER *)0x0) {
                                                              if (local_a8 == (_STACK *)0x0) {
                                                                local_a8 = sk_new_null();
                                                              }
                                                              sk_push(local_a8,local_88);
                                                              if (local_a0 == (BIO *)0x0) {
                                                                local_a0 = (BIO *)local_88;
                                                              }
                                                              if (local_a4 == (_STACK *)0x0) {
                                                                local_a4 = sk_new_null();
                                                              }
                                                              sk_push(local_a4,local_a0);
                                                              local_a0 = (BIO *)0x0;
                                                              ppbVar13 = local_34;
                                                            }
                                                            local_88 = (EVP_CIPHER *)ppbVar13[1];
                                                            iVar4 = local_2c;
                                                            local_34 = ppbVar13 + 1;
                                                            goto LAB_08086b37;
                                                          }
                                                          iVar4 = strcmp((char *)pbVar1,"-recip");
                                                          if (iVar4 == 0) {
                                                            local_98 = (BIO *)ppbVar13[1];
                                                            pEVar6 = (EVP_CIPHER *)local_98;
                                                            goto joined_r0x0808880e;
                                                          }
                                                          if (((uVar14 == 0x6d) &&
                                                              (pbVar1[2] == 100)) &&
                                                             (pbVar1[3] == 0)) {
                                                            if (ppbVar13[1] != (byte *)0x0) {
                                                              local_34 = ppbVar13 + 1;
                                                              local_78 = EVP_get_digestbyname
                                                                                   ((char *)ppbVar13
                                                  [1]);
                                                  iVar4 = local_2c;
                                                  if (local_78 != (EVP_MD *)0x0) goto LAB_08086b37;
                                                  BIO_printf(bio_err,"Unknown digest %s\n",*local_34
                                                             ,0x6d);
                                                  }
                                                  goto LAB_08086ba4;
                                                  }
                                                  iVar4 = strcmp((char *)pbVar1,"-inkey");
                                                  if (iVar4 == 0) {
                                                    if (ppbVar13[1] == (byte *)0x0)
                                                    goto LAB_08086ba4;
                                                    if (local_a0 != (BIO *)0x0) {
                                                      if (local_88 == (EVP_CIPHER *)0x0)
                                                      goto LAB_080874e0;
                                                      if (local_a8 == (_STACK *)0x0) {
                                                        local_a8 = sk_new_null();
                                                      }
                                                      sk_push(local_a8,local_88);
                                                      if (local_a4 == (_STACK *)0x0) {
                                                        local_a4 = sk_new_null();
                                                      }
                                                      sk_push(local_a4,local_a0);
                                                      local_88 = (EVP_CIPHER *)0x0;
                                                      ppbVar13 = local_34;
                                                    }
                                                    local_a0 = (BIO *)ppbVar13[1];
                                                    iVar4 = local_2c;
                                                    local_34 = ppbVar13 + 1;
                                                    goto LAB_08086b37;
                                                  }
                                                  pcVar23 = "-keyform";
                                                  iVar9 = iVar4;
                                                  iVar12 = strcmp((char *)pbVar1,"-keyform");
                                                  if (iVar12 == 0) {
                                                    if (ppbVar13[1] == (byte *)0x0)
                                                    goto LAB_08086ba4;
                                                    local_34 = ppbVar13 + 1;
                                                    local_7c = str2fmt(ppbVar13[1],pcVar23,iVar4,
                                                                       iVar9);
                                                    iVar4 = local_2c;
                                                    goto LAB_08086b37;
                                                  }
                                                  iVar4 = strcmp((char *)pbVar1,"-certfile");
                                                  if (iVar4 == 0) {
                                                    local_94 = (X509 *)ppbVar13[1];
                                                    pEVar6 = (EVP_CIPHER *)local_94;
                                                  }
                                                  else {
                                                    iVar4 = strcmp((char *)pbVar1,"-CAfile");
                                                    if (iVar4 == 0) {
                                                      local_4c = (EVP_CIPHER *)ppbVar13[1];
                                                      pEVar6 = local_4c;
                                                    }
                                                    else {
                                                      iVar4 = strcmp((char *)pbVar1,"-CApath");
                                                      if (iVar4 == 0) {
                                                        local_48 = (EVP_CIPHER *)ppbVar13[1];
                                                        pEVar6 = local_48;
                                                        goto joined_r0x0808880e;
                                                      }
                                                      if (((uVar14 == 0x69) && (pbVar1[2] == 0x6e))
                                                         && (pbVar1[3] == 0)) {
                                                        local_6c = (char *)ppbVar13[1];
                                                        pEVar6 = (EVP_CIPHER *)local_6c;
                                                        goto joined_r0x080883b4;
                                                      }
                                                      pcVar23 = "-inform";
                                                      iVar9 = iVar4;
                                                      iVar12 = strcmp((char *)pbVar1,"-inform");
                                                      if (iVar12 == 0) {
                                                        if (ppbVar13[1] == (byte *)0x0)
                                                        goto LAB_08086ba4;
                                                        local_34 = ppbVar13 + 1;
                                                        local_74 = str2fmt(ppbVar13[1],pcVar23,iVar4
                                                                           ,iVar9);
                                                        iVar4 = local_2c;
                                                        goto LAB_08086b37;
                                                      }
                                                      pcVar23 = "-outform";
                                                      pbVar17 = pbVar18;
                                                      iVar4 = strcmp((char *)pbVar1,"-outform");
                                                      if (iVar4 == 0) {
                                                        if (ppbVar13[1] != (byte *)0x0) {
                                                          local_34 = ppbVar13 + 1;
                                                          local_70 = str2fmt(ppbVar13[1],pcVar23,
                                                                             pbVar18,pbVar17);
                                                          iVar4 = local_2c;
                                                          goto LAB_08086b37;
                                                        }
                                                        goto LAB_08086ba4;
                                                      }
                                                      iVar4 = strcmp((char *)pbVar1,"-out");
                                                      if (iVar4 != 0) {
                                                        pcVar23 = "-content";
                                                        uVar16 = uVar14;
                                                        iVar4 = strcmp((char *)pbVar1,"-content");
                                                        if (iVar4 == 0) {
                                                          local_60 = (EVP_CIPHER *)ppbVar13[1];
                                                          pEVar6 = local_60;
                                                          goto joined_r0x0808880e;
                                                        }
                                                        iVar4 = args_verify(&local_34,0,&local_2c,
                                                                            bio_err,&local_24,
                                                                            pcVar23,uVar14,uVar16);
                                                        if (iVar4 == 0) {
                                                          local_9c = (X509_STORE *)
                                                                     EVP_get_cipherbyname
                                                                               ((char *)(*local_34 +
                                                                                        1));
                                                          iVar4 = local_2c;
                                                          if (local_9c == (X509_STORE *)0x0) {
                                                            local_2c = 1;
                                                            iVar4 = 1;
                                                          }
                                                          goto LAB_08086b37;
                                                        }
                                                        goto LAB_08086a5b;
                                                      }
                                                      local_68 = (EVP_CIPHER *)ppbVar13[1];
                                                      pEVar6 = local_68;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
joined_r0x0808880e:
                                                  if (pEVar6 == (EVP_CIPHER *)0x0)
                                                  goto LAB_08086ba4;
                                                  local_34 = ppbVar13 + 1;
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
        }
      }
LAB_08086b37:
      local_34 = local_34 + 1;
      if (iVar4 != 0) goto LAB_08086b46;
      goto LAB_08086a68;
    }
LAB_08086b46:
    uVar14 = local_ac & 0x40;
    if (uVar14 == 0) {
      if ((local_a4 == (_STACK *)0x0) && (local_a8 == (_STACK *)0x0)) {
        if (local_ac == 0x22) {
          if ((local_98 != (BIO *)0x0) || (local_a0 != (BIO *)0x0)) {
LAB_08087490:
            local_a4 = (_STACK *)0x0;
            local_a8 = (_STACK *)0x0;
            goto LAB_080872cf;
          }
          BIO_printf(bio_err,"No recipient certificate or key specified\n");
          local_a4 = (_STACK *)0x0;
        }
        else if (local_ac == 0x11) {
          bVar2 = true;
          local_a4 = (_STACK *)0x0;
          local_a8 = (_STACK *)0x0;
          if (*local_34 != (byte *)0x0) goto LAB_080872cf;
          BIO_printf(bio_err,"No recipient(s) certificate(s) specified\n");
        }
        else {
          if (local_ac != 0) goto LAB_08087490;
          local_a4 = (_STACK *)0x0;
        }
LAB_08086b9c:
        local_2c = 1;
        local_a8 = (_STACK *)0x0;
      }
      else {
        BIO_puts(bio_err,"Multiple signers or keys not allowed\n");
      }
LAB_08086ba4:
      BIO_printf(bio_err,"Usage smime [options] cert.pem ...\n");
      BIO_printf(bio_err,"where options are\n");
      BIO_printf(bio_err,"-encrypt       encrypt message\n");
      BIO_printf(bio_err,"-decrypt       decrypt encrypted message\n");
      BIO_printf(bio_err,"-sign          sign message\n");
      BIO_printf(bio_err,"-verify        verify signed message\n");
      BIO_printf(bio_err,"-pk7out        output PKCS#7 structure\n");
      BIO_printf(bio_err,"-des3          encrypt with triple DES\n");
      BIO_printf(bio_err,"-des           encrypt with DES\n");
      BIO_printf(bio_err,"-seed          encrypt with SEED\n");
      BIO_printf(bio_err,"-rc2-40        encrypt with RC2-40 (default)\n");
      BIO_printf(bio_err,"-rc2-64        encrypt with RC2-64\n");
      BIO_printf(bio_err,"-rc2-128       encrypt with RC2-128\n");
      BIO_printf(bio_err,"-aes128, -aes192, -aes256\n");
      BIO_printf(bio_err,"               encrypt PEM output with cbc aes\n");
      BIO_printf(bio_err,"-camellia128, -camellia192, -camellia256\n");
      BIO_printf(bio_err,"               encrypt PEM output with cbc camellia\n");
      BIO_printf(bio_err,"-nointern      don\'t search certificates in message for signer\n");
      BIO_printf(bio_err,"-nosigs        don\'t verify message signature\n");
      BIO_printf(bio_err,"-noverify      don\'t verify signers certificate\n");
      BIO_printf(bio_err,"-nocerts       don\'t include signers certificate when signing\n");
      BIO_printf(bio_err,"-nodetach      use opaque signing\n");
      BIO_printf(bio_err,"-noattr        don\'t include any signed attributes\n");
      BIO_printf(bio_err,"-binary        don\'t translate message to text\n");
      BIO_printf(bio_err,"-certfile file other certificates file\n");
      BIO_printf(bio_err,"-signer file   signer certificate file\n");
      BIO_printf(bio_err,"-recip  file   recipient certificate file for decryption\n");
      BIO_printf(bio_err,"-in file       input file\n");
      BIO_printf(bio_err,"-inform arg    input format SMIME (default), PEM or DER\n");
      BIO_printf(bio_err,"-inkey file    input private key (if not signer or recipient)\n");
      BIO_printf(bio_err,"-keyform arg   input private key format (PEM or ENGINE)\n");
      BIO_printf(bio_err,"-out file      output file\n");
      BIO_printf(bio_err,"-outform arg   output format SMIME (default), PEM or DER\n");
      BIO_printf(bio_err,"-content file  supply or override content for detached signature\n");
      BIO_printf(bio_err,"-to addr       to address\n");
      BIO_printf(bio_err,"-from ad       from address\n");
      BIO_printf(bio_err,"-subject s     subject\n");
      BIO_printf(bio_err,"-text          include or delete text MIME headers\n");
      BIO_printf(bio_err,"-CApath dir    trusted certificates directory\n");
      BIO_printf(bio_err,"-CAfile file   trusted certificates file\n");
      BIO_printf(bio_err,
                 "-crl_check     check revocation status of signer\'s certificate using CRLs\n");
      BIO_printf(bio_err,
                 "-crl_check_all check revocation status of signer\'s certificate chain using CRLs\n"
                );
      BIO_printf(bio_err,"-engine e      use engine e, possibly a hardware device.\n");
      BIO_printf(bio_err,"-passin arg    input file pass phrase source\n");
      BIO_printf(bio_err,"-rand file%cfile%c...\n",0x3a,0x3a);
      BIO_printf(bio_err,"               load the file (or the files in the directory) into\n");
      BIO_printf(bio_err,"               the random number generator\n");
      pcVar23 = "cert.pem       recipient certificate(s) for encryption\n";
LAB_08086efd:
      pXVar15 = (X509 *)0x0;
      p7 = (PKCS7 *)0x0;
      iVar4 = 1;
      BIO_printf(bio_err,pcVar23);
      local_a0 = (BIO *)0x0;
      local_98 = (BIO *)0x0;
      local_90 = (EVP_CIPHER *)0x0;
      local_8c = (EVP_CIPHER *)0x0;
      local_94 = (X509 *)0x0;
      local_9c = (X509_STORE *)0x0;
      pkey_00 = (EVP_PKEY *)0x0;
    }
    else {
      if ((local_a0 != (BIO *)0x0) && (local_88 == (EVP_CIPHER *)0x0)) {
LAB_080874e0:
        BIO_puts(bio_err,"Illegal -inkey without -signer\n");
        goto LAB_08086ba4;
      }
      if (local_88 != (EVP_CIPHER *)0x0) {
        if (local_a8 == (_STACK *)0x0) {
          local_a8 = sk_new_null();
        }
        sk_push(local_a8,local_88);
        if (local_a4 == (_STACK *)0x0) {
          local_a4 = sk_new_null();
        }
        if (local_a0 != (BIO *)0x0) {
          local_88 = (EVP_CIPHER *)local_a0;
        }
        sk_push(local_a4,local_88);
      }
      if (local_a8 == (_STACK *)0x0) {
        BIO_printf(bio_err,"No signer certificate specified\n");
        bVar2 = true;
        goto LAB_08086b9c;
      }
      bVar2 = true;
      local_a0 = (BIO *)0x0;
      local_88 = (EVP_CIPHER *)0x0;
      iVar4 = local_2c;
LAB_080872cf:
      if (iVar4 != 0) goto LAB_08086ba4;
      pcVar23 = (char *)0x0;
      uVar5 = setup_engine(bio_err,local_8c,0);
      iVar4 = app_passwd(bio_err,local_90,0,&local_28,0);
      if (iVar4 == 0) {
        pcVar23 = "Error getting password\n";
        goto LAB_08086efd;
      }
      if (bVar2) {
        pcVar23 = (char *)(uint)(local_5c != (byte *)0x0);
        app_RAND_load_file(0,bio_err,pcVar23);
        if (local_5c != (byte *)0x0) {
          pcVar23 = (char *)app_RAND_load_files(local_5c);
          BIO_printf(bio_err,"%ld semi-random bytes loaded\n",pcVar23);
        }
      }
      pEVar6 = (EVP_CIPHER *)((uint)local_80 & 0xffffffbf);
      if (uVar14 != 0) {
        pEVar6 = local_80;
      }
      if ((local_ac & 0x10) == 0) {
        if (((uint)pEVar6 & 0x80) == 0) {
          local_40 = "w";
          if ((local_ac & 0x20) != 0) goto LAB_080875a0;
          local_44 = "r";
          goto LAB_08087367;
        }
        local_40 = "wb";
        if ((local_ac & 0x20) == 0) {
          local_44 = "rb";
          goto LAB_08087367;
        }
LAB_080875a0:
        uVar16 = local_ac & 0x20;
        local_44 = "r";
        if (local_74 == 1) {
          local_44 = "rb";
        }
LAB_080875b6:
        local_8c = (EVP_CIPHER *)0x0;
        if (local_94 == (X509 *)0x0) {
          local_90 = (EVP_CIPHER *)0x0;
LAB_080875f5:
          bVar20 = local_ac == 0x22;
          if (bVar20 && local_98 != (BIO *)0x0) {
            local_94 = (X509 *)load_cert(bio_err,local_98,3,0,uVar5,"recipient certificate file");
            if (local_94 != (X509 *)0x0) goto LAB_080879a3;
            pkey_00 = (EVP_PKEY *)0x0;
            pXVar15 = (X509 *)0x0;
            p7 = (PKCS7 *)0x0;
            iVar4 = 2;
            ERR_print_errors(bio_err);
            local_a0 = (BIO *)0x0;
            local_98 = (BIO *)0x0;
            local_9c = (X509_STORE *)0x0;
          }
          else {
            if (local_ac == 0x22) {
              local_94 = (X509 *)0x0;
LAB_080879a3:
              if (local_a0 == (BIO *)0x0) {
                local_a0 = local_98;
LAB_08087a49:
                if (local_a0 == (BIO *)0x0) {
                  pkey_00 = (EVP_PKEY *)0x0;
                  goto LAB_08087637;
                }
              }
            }
            else {
              if (local_ac != 0x53) {
                bVar20 = false;
                local_94 = (X509 *)0x0;
                pkey_00 = (EVP_PKEY *)0x0;
                goto LAB_08087637;
              }
              local_94 = (X509 *)0x0;
              if (local_a0 == (BIO *)0x0) {
                local_a0 = (BIO *)local_88;
                goto LAB_08087a49;
              }
            }
            pcVar23 = "signing key file";
            pkey_00 = (EVP_PKEY *)
                      load_key(bio_err,local_a0,local_7c,0,local_28,uVar5,"signing key file");
            if (pkey_00 != (EVP_PKEY *)0x0) goto LAB_08087637;
            local_a0 = (BIO *)0x0;
            local_98 = (BIO *)0x0;
            pXVar15 = (X509 *)0x0;
            local_9c = (X509_STORE *)0x0;
            p7 = (PKCS7 *)0x0;
            iVar4 = 2;
          }
        }
        else {
LAB_080875ca:
          local_90 = (EVP_CIPHER *)load_certs(bio_err,local_94,3,0,uVar5,"certificate file");
          if (local_90 != (EVP_CIPHER *)0x0) goto LAB_080875f5;
          ERR_print_errors(bio_err);
LAB_08087401:
          local_98 = (BIO *)0x0;
          local_a0 = (BIO *)0x0;
          pkey_00 = (EVP_PKEY *)0x0;
          pXVar15 = (X509 *)0x0;
          local_94 = (X509 *)0x0;
          local_9c = (X509_STORE *)0x0;
          p7 = (PKCS7 *)0x0;
          iVar4 = 2;
        }
      }
      else {
        local_40 = "w";
        if (local_70 == 1) {
          local_40 = "wb";
        }
        if ((local_ac & 0x20) != 0) goto LAB_080875a0;
        local_44 = "r";
        if (((uint)pEVar6 & 0x80) != 0) {
          local_44 = "rb";
        }
LAB_08087367:
        if (local_ac != 0x11) {
          uVar16 = 0;
          goto LAB_080875b6;
        }
        if (local_9c == (X509_STORE *)0x0) {
          local_9c = (X509_STORE *)EVP_rc2_40_cbc();
        }
        local_8c = (EVP_CIPHER *)sk_new_null();
        pbVar1 = *local_34;
        while (pbVar1 != (byte *)0x0) {
          pvVar7 = (void *)load_cert(bio_err,pbVar1,3,0,uVar5,"recipient certificate file");
          if (pvVar7 == (void *)0x0) {
            local_90 = (EVP_CIPHER *)0x0;
            goto LAB_08087401;
          }
          sk_push((_STACK *)local_8c,pvVar7);
          pbVar1 = local_34[1];
          local_34 = local_34 + 1;
        }
        uVar16 = 0;
        if (local_94 != (X509 *)0x0) goto LAB_080875ca;
        bVar20 = false;
        local_90 = (EVP_CIPHER *)0x0;
        pkey_00 = (EVP_PKEY *)0x0;
        local_94 = (X509 *)0x0;
LAB_08087637:
        if ((EVP_CIPHER *)local_6c == (EVP_CIPHER *)0x0) {
          local_98 = BIO_new_fp(stdin,0);
LAB_0808765f:
          local_6c = pcVar23;
          if (uVar16 == 0) {
            p7 = (PKCS7 *)0x0;
          }
          else {
            if (local_74 == 6) {
              p7 = SMIME_read_PKCS7(local_98,&local_30);
            }
            else if (local_74 == 3) {
              local_6c = (char *)0x0;
              p7 = PEM_read_bio_PKCS7(local_98,(PKCS7 **)0x0,(undefined1 *)0x0,(void *)0x0);
            }
            else {
              if (local_74 != 1) {
                pcVar23 = "Bad input format for PKCS#7 file\n";
                goto LAB_08087690;
              }
              p7 = d2i_PKCS7_bio(local_98,(PKCS7 **)0x0);
            }
            if (p7 == (PKCS7 *)0x0) {
              pcVar23 = "Error reading S/MIME message\n";
LAB_08087cdf:
              pXVar15 = (X509 *)0x0;
              iVar4 = 2;
              BIO_printf(bio_err,pcVar23,local_6c);
              local_a0 = (BIO *)0x0;
              local_9c = (X509_STORE *)0x0;
              goto LAB_08086f46;
            }
            if (local_60 != (EVP_CIPHER *)0x0) {
              BIO_free(local_30);
              local_30 = BIO_new_file((char *)local_60,"rb");
              if (local_30 == (BIO *)0x0) {
                pcVar23 = "Can\'t read content file %s\n";
                local_6c = (char *)local_60;
                goto LAB_08087cdf;
              }
            }
          }
          if (local_68 == (EVP_CIPHER *)0x0) {
            local_a0 = BIO_new_fp(stdout,0);
          }
          else {
            local_a0 = BIO_new_file((char *)local_68,local_40);
            if (local_a0 == (BIO *)0x0) {
              pXVar15 = (X509 *)0x0;
              iVar4 = 2;
              BIO_printf(bio_err,"Can\'t open output file %s\n",local_68);
              local_9c = (X509_STORE *)0x0;
              goto LAB_08086f46;
            }
          }
          local_80 = pEVar6;
          if (local_ac == 0x24) {
            local_9c = (X509_STORE *)setup_verify(bio_err,local_4c,local_48);
            if (local_9c != (X509_STORE *)0x0) {
              X509_STORE_set_verify_cb(local_9c,smime_cb);
              if (local_24 != (X509_VERIFY_PARAM *)0x0) {
                X509_STORE_set1_param(local_9c,local_24);
              }
              local_6c = (char *)local_48;
              if (uVar14 != 0) {
LAB_080877a0:
                local_80 = (EVP_CIPHER *)((uint)pEVar6 | 0x8000);
                goto LAB_080877a8;
              }
              goto LAB_08087892;
            }
            pXVar15 = (X509 *)0x0;
            iVar4 = 2;
          }
          else if (local_ac == 0x11) {
            local_80 = (EVP_CIPHER *)((uint)pEVar6 | 0x1000);
            if (!bVar3) {
              local_80 = pEVar6;
            }
            local_6c = (char *)local_9c;
            p7 = PKCS7_encrypt((stack_st_X509 *)local_8c,local_98,(EVP_CIPHER *)local_9c,
                               (int)local_80);
            local_9c = (X509_STORE *)0x0;
LAB_08087b7f:
            if (p7 == (PKCS7 *)0x0) goto LAB_08087b87;
LAB_080878b9:
            if (local_58 != (EVP_CIPHER *)0x0) {
              BIO_printf(local_a0,"To: %s\n",local_58);
              local_6c = (char *)local_58;
            }
            if (local_54 != (EVP_CIPHER *)0x0) {
              BIO_printf(local_a0,"From: %s\n",local_54);
              local_6c = (char *)local_54;
            }
            local_48 = (EVP_CIPHER *)local_6c;
            if (local_50 != (EVP_CIPHER *)0x0) {
              BIO_printf(local_a0,"Subject: %s\n",local_50);
              local_48 = local_50;
            }
            if (local_70 == 6) {
              pBVar11 = local_30;
              if (local_ac != 0x76) {
                pBVar11 = local_98;
              }
              pXVar15 = (X509 *)0x0;
              iVar4 = 0;
              SMIME_write_PKCS7(local_a0,p7,pBVar11,(int)local_80);
            }
            else if (local_70 == 3) {
              pXVar15 = (X509 *)0x0;
              iVar4 = 0;
              PEM_write_bio_PKCS7_stream(local_a0,p7,local_98,(int)local_80);
            }
            else if (local_70 == 1) {
              pXVar15 = (X509 *)0x0;
              iVar4 = 0;
              i2d_PKCS7_bio_stream(local_a0,p7,local_98,(int)local_80);
            }
            else {
              pcVar23 = "Bad output format for PKCS#7 file\n";
LAB_08087939:
              pXVar15 = (X509 *)0x0;
              iVar4 = 4;
              BIO_printf(bio_err,pcVar23,local_48);
            }
          }
          else {
            local_9c = (X509_STORE *)0x0;
            local_48 = (EVP_CIPHER *)local_6c;
            if (uVar14 != 0) {
              if (local_ac != 0x53) goto LAB_080877a0;
              if (((uint)pEVar6 & 0x40) == 0) {
                local_80 = (EVP_CIPHER *)((uint)pEVar6 | 0x1000);
                if (!bVar3) {
                  local_80 = pEVar6;
                }
              }
              else {
                local_80 = (EVP_CIPHER *)((uint)pEVar6 | 0x1000);
                if (local_70 != 6) {
                  local_80 = pEVar6;
                }
              }
              local_80 = (EVP_CIPHER *)((uint)local_80 | 0x4000);
              p7 = PKCS7_sign((X509 *)0x0,(EVP_PKEY *)0x0,(stack_st_X509 *)local_90,local_98,
                              (int)local_80);
              if (p7 == (PKCS7 *)0x0) {
                pXVar15 = (X509 *)0x0;
                local_9c = (X509_STORE *)0x0;
                iVar4 = 3;
                goto LAB_08086f46;
              }
              local_9c = (X509_STORE *)0x0;
LAB_080877a8:
              for (iVar4 = 0; iVar9 = sk_num(local_a8), iVar4 < iVar9; iVar4 = iVar4 + 1) {
                local_88 = (EVP_CIPHER *)sk_value(local_a8,iVar4);
                pvVar7 = sk_value(local_a4,iVar4);
                pXVar15 = (X509 *)load_cert(bio_err,local_88,3,0,uVar5,"signer certificate");
                pkey = pkey_00;
                if (pXVar15 == (X509 *)0x0) {
LAB_08087bbc:
                  iVar4 = 3;
                  pkey_00 = pkey;
                  goto LAB_08086f46;
                }
                local_6c = "signing key file";
                pkey = (EVP_PKEY *)
                       load_key(bio_err,pvVar7,local_7c,0,local_28,uVar5,"signing key file");
                if ((pkey == (EVP_PKEY *)0x0) ||
                   (pPVar8 = PKCS7_sign_add_signer(p7,pXVar15,pkey,local_78,(int)local_80),
                   pPVar8 == (PKCS7_SIGNER_INFO *)0x0)) goto LAB_08087bbc;
                X509_free(pXVar15);
                pkey_00 = (EVP_PKEY *)0x0;
                EVP_PKEY_free(pkey);
              }
              local_48 = (EVP_CIPHER *)local_6c;
              if (local_ac == 0x53) {
                if ((((uint)local_80 & 0x1000) == 0) &&
                   (local_6c = (char *)local_80, iVar4 = PKCS7_final(p7,local_98,(int)local_80),
                   iVar4 == 0)) {
                  pXVar15 = (X509 *)0x0;
                  iVar4 = 3;
                  goto LAB_08086f46;
                }
                goto LAB_08087b7f;
              }
            }
LAB_08087892:
            if (p7 == (PKCS7 *)0x0) {
LAB_08087b87:
              pXVar15 = (X509 *)0x0;
              p7 = (PKCS7 *)0x0;
              iVar4 = 3;
              BIO_printf(bio_err,"Error creating PKCS#7 structure\n");
            }
            else if (bVar20) {
              pXVar15 = (X509 *)0x0;
              iVar4 = 0;
              iVar9 = PKCS7_decrypt(p7,pkey_00,local_94,local_a0,(int)local_80);
              if (iVar9 == 0) {
                iVar4 = 4;
                BIO_printf(bio_err,"Error decrypting PKCS#7 structure\n");
              }
            }
            else if (local_ac == 0x24) {
              iVar4 = PKCS7_verify(p7,(stack_st_X509 *)local_90,local_9c,local_30,local_a0,
                                   (int)local_80);
              if (iVar4 == 0) {
                pcVar23 = "Verification failure\n";
                goto LAB_08087939;
              }
              BIO_printf(bio_err,"Verification successful\n");
              p_Var10 = (_STACK *)PKCS7_get0_signers(p7,(stack_st_X509 *)local_90,(int)local_80);
              if (local_88 != (EVP_CIPHER *)0x0) {
                pBVar11 = BIO_new_file((char *)local_88,"w");
                if (pBVar11 == (BIO *)0x0) {
                  pXVar15 = (X509 *)0x0;
                  iVar4 = 5;
                  BIO_printf(bio_err,"Error writing signers to %s\n",local_88,extraout_EDX);
                  goto LAB_08086f46;
                }
                for (iVar4 = 0; iVar9 = sk_num(p_Var10), iVar4 < iVar9; iVar4 = iVar4 + 1) {
                  pXVar15 = (X509 *)sk_value(p_Var10,iVar4);
                  PEM_write_bio_X509(pBVar11,pXVar15);
                }
                BIO_free(pBVar11);
              }
              pXVar15 = (X509 *)0x0;
              iVar4 = 0;
              sk_free(p_Var10);
            }
            else {
              local_6c = (char *)local_48;
              if (local_ac != 0x35) goto LAB_080878b9;
              pXVar15 = (X509 *)0x0;
              iVar4 = 0;
              PEM_write_bio_PKCS7(local_a0,p7);
            }
          }
        }
        else {
          local_98 = BIO_new_file(local_6c,local_44);
          if (local_98 != (BIO *)0x0) goto LAB_0808765f;
          pcVar23 = "Can\'t open input file %s\n";
LAB_08087690:
          pXVar15 = (X509 *)0x0;
          p7 = (PKCS7 *)0x0;
          iVar4 = 2;
          BIO_printf(bio_err,pcVar23,local_6c);
          local_a0 = (BIO *)0x0;
          local_9c = (X509_STORE *)0x0;
        }
      }
    }
LAB_08086f46:
    if (bVar2) {
      app_RAND_write_file(0,bio_err);
    }
    if (iVar4 == 0) goto LAB_08086f69;
  }
  ERR_print_errors(bio_err);
LAB_08086f69:
  sk_pop_free((_STACK *)local_8c,X509_free);
  sk_pop_free((_STACK *)local_90,X509_free);
  if (local_24 != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(local_24);
  }
  if (local_a8 != (_STACK *)0x0) {
    sk_free(local_a8);
  }
  if (local_a4 != (_STACK *)0x0) {
    sk_free(local_a4);
  }
  X509_STORE_free(local_9c);
  X509_free((X509 *)0x0);
  X509_free(local_94);
  X509_free(pXVar15);
  EVP_PKEY_free(pkey_00);
  PKCS7_free(p7);
  BIO_free(local_98);
  BIO_free(local_30);
  BIO_free_all(local_a0);
  if (local_28 != (void *)0x0) {
    CRYPTO_free(local_28);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

