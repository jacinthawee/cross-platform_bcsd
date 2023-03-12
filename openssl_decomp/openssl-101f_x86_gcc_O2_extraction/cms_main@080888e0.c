
/* WARNING: Type propagation algorithm not settling */

int cms_main(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  char *mode;
  BIO_METHOD *type;
  CMS_SignerInfo *pCVar10;
  _STACK *p_Var11;
  BIO *pBVar12;
  int iVar13;
  CMS_RecipientInfo *pCVar14;
  X509 *pXVar15;
  void *pvVar16;
  uchar *bytes;
  EVP_PKEY *pEVar17;
  int iVar18;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar19;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 extraout_ECX_14;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar20;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  undefined4 extraout_EDX_10;
  undefined4 extraout_EDX_11;
  byte *extraout_EDX_12;
  undefined4 extraout_EDX_13;
  undefined4 extraout_EDX_14;
  undefined4 extraout_EDX_15;
  undefined4 extraout_EDX_16;
  undefined4 extraout_EDX_17;
  byte **ppbVar21;
  EVP_PKEY *pass;
  uint uVar22;
  EVP_PKEY *cms;
  byte *pbVar23;
  byte *pbVar24;
  CMS_ReceiptRequest *a;
  int in_GS_OFFSET;
  bool bVar26;
  bool bVar27;
  byte bVar28;
  BIO *pBVar29;
  char *pcVar30;
  code *pcVar31;
  uint uVar32;
  uint local_104;
  _STACK *local_100;
  _STACK *local_fc;
  _STACK *local_f8;
  _STACK *local_f4;
  BIO *local_ec;
  BIO *local_e8;
  uchar *local_e4;
  CMS_ContentInfo *local_e0;
  X509_STORE *local_dc;
  EVP_PKEY *local_d8;
  BIO *local_d4;
  X509 *local_d0;
  uchar *local_cc;
  _STACK *local_c8;
  X509 *local_c4;
  X509_VERIFY_PARAM *local_c0;
  _STACK *local_bc;
  byte *local_b8;
  uint local_b4;
  int local_b0;
  EVP_CIPHER *local_ac;
  int local_a4;
  byte *local_a0;
  byte *local_9c;
  byte *local_98;
  undefined4 local_94;
  ASN1_STRING *local_90;
  byte *local_8c;
  int local_88;
  byte *local_84;
  byte *local_80;
  EVP_MD *local_78;
  ASN1_STRING *local_74;
  byte *local_68;
  byte *local_64;
  byte *local_60;
  byte *local_5c;
  byte *local_58;
  byte **local_48;
  BIO *local_44;
  uint local_40;
  void *local_3c;
  X509_VERIFY_PARAM *local_38;
  CMS_ReceiptRequest *local_34;
  int local_30;
  undefined local_2c [4];
  int local_28;
  ASN1_STRING *local_24;
  int local_20;
  byte *pbVar25;
  
  bVar28 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_44 = (BIO *)0x0;
  local_40 = 0;
  local_3c = (void *)0x0;
  local_38 = (X509_VERIFY_PARAM *)0x0;
  local_48 = (byte **)(param_2 + 4);
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar7 = load_config(bio_err,0);
  if (iVar7 == 0) {
    local_c0 = (X509_VERIFY_PARAM *)0x0;
    pass = (EVP_PKEY *)0x0;
    local_cc = (uchar *)0x0;
    local_e4 = (uchar *)0x0;
    bVar2 = false;
    a = (CMS_ReceiptRequest *)0x0;
    local_f4 = (_STACK *)0x0;
    local_100 = (_STACK *)0x0;
    cms = (EVP_PKEY *)0x0;
    local_d4 = (BIO *)0x0;
    local_ec = (BIO *)0x0;
    iVar7 = 1;
    local_e8 = (BIO *)0x0;
    local_c8 = (_STACK *)0x0;
    local_bc = (_STACK *)0x0;
    local_d8 = (EVP_PKEY *)0x0;
    local_d0 = (X509 *)0x0;
    local_c4 = (X509 *)0x0;
    local_dc = (X509_STORE *)0x0;
    local_e0 = (CMS_ContentInfo *)0x0;
    local_f8 = (_STACK *)0x0;
    local_fc = (_STACK *)0x0;
    goto LAB_0808946b;
  }
  local_c0 = (X509_VERIFY_PARAM *)0x0;
  local_74 = (ASN1_STRING *)0x0;
  local_90 = (ASN1_STRING *)0x0;
  local_98 = (byte *)0x0;
  local_cc = (uchar *)0x0;
  local_e4 = (uchar *)0x0;
  local_d8 = (EVP_PKEY *)0x0;
  local_94 = 3;
  local_88 = 6;
  local_a4 = 6;
  local_d4 = (BIO *)0x6;
  local_78 = (EVP_MD *)0x0;
  bVar2 = false;
  local_d0 = (X509 *)0x0;
  local_dc = (X509_STORE *)0x0;
  local_58 = (byte *)0x0;
  local_5c = (byte *)0x0;
  local_60 = (byte *)0x0;
  local_64 = (byte *)0x0;
  local_68 = (byte *)0x0;
  local_f4 = (_STACK *)0x0;
  local_100 = (_STACK *)0x0;
  local_b0 = -1;
  bVar5 = false;
  bVar6 = false;
  bVar4 = false;
  bVar3 = false;
  local_b4 = 0x40;
  local_ac = (EVP_CIPHER *)0x0;
  local_8c = (byte *)0x0;
  local_80 = (byte *)0x0;
  local_ec = (BIO *)0x0;
  local_e0 = (CMS_ContentInfo *)0x0;
  local_f8 = (_STACK *)0x0;
  local_fc = (_STACK *)0x0;
  local_e8 = (BIO *)0x0;
  local_b8 = (byte *)0x0;
  local_a0 = (byte *)0x0;
  local_84 = (byte *)0x0;
  local_9c = (byte *)0x0;
  local_104 = 0;
LAB_08088ae0:
  uVar8 = local_40;
  if (local_40 == 0) {
LAB_08088af0:
    ppbVar21 = local_48;
    pbVar1 = *local_48;
    if (pbVar1 == (byte *)0x0) goto LAB_08088efa;
    bVar26 = *pbVar1 < 0x2d;
    bVar27 = *pbVar1 == 0x2d;
    if (!bVar27) goto LAB_08088efa;
    iVar7 = 9;
    pbVar23 = pbVar1;
    pbVar25 = (byte *)"-encrypt";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar26 = *pbVar23 < *pbVar25;
      bVar27 = *pbVar23 == *pbVar25;
      pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
      pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
    } while (bVar27);
    uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
    bVar26 = false;
    bVar27 = uVar8 == 0;
    if (bVar27) {
      local_104 = 0x11;
      local_48 = ppbVar21;
    }
    else {
      iVar7 = 9;
      pbVar23 = pbVar1;
      pbVar25 = (byte *)"-decrypt";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar26 = *pbVar23 < *pbVar25;
        bVar27 = *pbVar23 == *pbVar25;
        pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
        pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
      } while (bVar27);
      uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
      bVar26 = false;
      bVar27 = uVar8 == 0;
      if (bVar27) {
        local_104 = 0x22;
        local_48 = ppbVar21;
      }
      else {
        iVar7 = 6;
        pbVar23 = pbVar1;
        pbVar25 = (byte *)"-sign";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar26 = *pbVar23 < *pbVar25;
          bVar27 = *pbVar23 == *pbVar25;
          pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
          pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
        } while (bVar27);
        uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
        bVar26 = false;
        bVar27 = uVar8 == 0;
        if (bVar27) {
          local_104 = 0x53;
          local_48 = ppbVar21;
        }
        else {
          iVar7 = 0xe;
          pbVar23 = pbVar1;
          pbVar25 = (byte *)"-sign_receipt";
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar26 = *pbVar23 < *pbVar25;
            bVar27 = *pbVar23 == *pbVar25;
            pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
            pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
          } while (bVar27);
          uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
          bVar26 = false;
          bVar27 = uVar8 == 0;
          if (bVar27) {
            local_104 = 0x3f;
            local_48 = ppbVar21;
          }
          else {
            iVar7 = 8;
            pbVar23 = pbVar1;
            pbVar25 = (byte *)"-resign";
            do {
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              bVar26 = *pbVar23 < *pbVar25;
              bVar27 = *pbVar23 == *pbVar25;
              pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
              pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
            } while (bVar27);
            uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
            bVar26 = false;
            bVar27 = uVar8 == 0;
            if (bVar27) {
              local_104 = 0x76;
              local_48 = ppbVar21;
            }
            else {
              iVar7 = 8;
              pbVar23 = pbVar1;
              pbVar25 = (byte *)"-verify";
              do {
                if (iVar7 == 0) break;
                iVar7 = iVar7 + -1;
                bVar26 = *pbVar23 < *pbVar25;
                bVar27 = *pbVar23 == *pbVar25;
                pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
              } while (bVar27);
              uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
              bVar26 = false;
              bVar27 = uVar8 == 0;
              if (bVar27) {
                local_104 = 0x24;
                local_48 = ppbVar21;
              }
              else {
                iVar7 = 0x10;
                pbVar23 = pbVar1;
                pbVar25 = (byte *)"-verify_retcode";
                do {
                  if (iVar7 == 0) break;
                  iVar7 = iVar7 + -1;
                  bVar26 = *pbVar23 < *pbVar25;
                  bVar27 = *pbVar23 == *pbVar25;
                  pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                  pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
                } while (bVar27);
                uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
                bVar26 = false;
                bVar27 = uVar8 == 0;
                if (bVar27) {
                  bVar6 = true;
                  local_48 = ppbVar21;
                }
                else {
                  iVar7 = 0x10;
                  pbVar23 = pbVar1;
                  pbVar25 = (byte *)"-verify_receipt";
                  do {
                    if (iVar7 == 0) break;
                    iVar7 = iVar7 + -1;
                    bVar26 = *pbVar23 < *pbVar25;
                    bVar27 = *pbVar23 == *pbVar25;
                    pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                    pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
                  } while (bVar27);
                  uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
                  bVar26 = false;
                  bVar27 = uVar8 == 0;
                  if (bVar27) {
                    local_a0 = local_48[1];
                    if (local_a0 == (byte *)0x0) goto LAB_08088fc4;
                    local_104 = 0x30;
                    local_48 = local_48 + 1;
                  }
                  else {
                    iVar7 = 8;
                    pbVar23 = pbVar1;
                    pbVar25 = (byte *)"-cmsout";
                    do {
                      if (iVar7 == 0) break;
                      iVar7 = iVar7 + -1;
                      bVar26 = *pbVar23 < *pbVar25;
                      bVar27 = *pbVar23 == *pbVar25;
                      pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                      pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
                    } while (bVar27);
                    uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
                    bVar26 = false;
                    bVar27 = uVar8 == 0;
                    if (bVar27) {
                      local_104 = 0x35;
                      local_48 = ppbVar21;
                    }
                    else {
                      iVar7 = 10;
                      pbVar23 = pbVar1;
                      pbVar25 = (byte *)"-data_out";
                      do {
                        if (iVar7 == 0) break;
                        iVar7 = iVar7 + -1;
                        bVar26 = *pbVar23 < *pbVar25;
                        bVar27 = *pbVar23 == *pbVar25;
                        pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                        pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
                      } while (bVar27);
                      uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
                      bVar26 = false;
                      bVar27 = uVar8 == 0;
                      if (bVar27) {
                        local_104 = 0x27;
                        local_48 = ppbVar21;
                      }
                      else {
                        iVar7 = 0xd;
                        pbVar23 = pbVar1;
                        pbVar25 = (byte *)"-data_create";
                        do {
                          if (iVar7 == 0) break;
                          iVar7 = iVar7 + -1;
                          bVar26 = *pbVar23 < *pbVar25;
                          bVar27 = *pbVar23 == *pbVar25;
                          pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                          pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
                        } while (bVar27);
                        uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
                        bVar26 = false;
                        bVar27 = uVar8 == 0;
                        if (bVar27) {
                          local_104 = 0x18;
                          local_48 = ppbVar21;
                        }
                        else {
                          iVar7 = 0xf;
                          pbVar23 = pbVar1;
                          pbVar25 = (byte *)"-digest_verify";
                          do {
                            if (iVar7 == 0) break;
                            iVar7 = iVar7 + -1;
                            bVar26 = *pbVar23 < *pbVar25;
                            bVar27 = *pbVar23 == *pbVar25;
                            pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                            pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
                          } while (bVar27);
                          uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
                          bVar26 = false;
                          bVar27 = uVar8 == 0;
                          if (bVar27) {
                            local_104 = 0x29;
                            local_48 = ppbVar21;
                          }
                          else {
                            iVar7 = 0xf;
                            pbVar23 = pbVar1;
                            pbVar25 = (byte *)"-digest_create";
                            do {
                              if (iVar7 == 0) break;
                              iVar7 = iVar7 + -1;
                              bVar26 = *pbVar23 < *pbVar25;
                              bVar27 = *pbVar23 == *pbVar25;
                              pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                              pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
                            } while (bVar27);
                            uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
                            bVar26 = false;
                            bVar27 = uVar8 == 0;
                            if (bVar27) {
                              local_104 = 0x1a;
                              local_48 = ppbVar21;
                            }
                            else {
                              iVar7 = 10;
                              pbVar23 = pbVar1;
                              pbVar25 = (byte *)"-compress";
                              do {
                                if (iVar7 == 0) break;
                                iVar7 = iVar7 + -1;
                                bVar26 = *pbVar23 < *pbVar25;
                                bVar27 = *pbVar23 == *pbVar25;
                                pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                                pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
                              } while (bVar27);
                              uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
                              bVar26 = false;
                              bVar27 = uVar8 == 0;
                              if (bVar27) {
                                local_104 = 0x1c;
                                local_48 = ppbVar21;
                              }
                              else {
                                iVar7 = 0xc;
                                pbVar23 = pbVar1;
                                pbVar25 = (byte *)"-uncompress";
                                do {
                                  pbVar24 = pbVar25;
                                  if (iVar7 == 0) break;
                                  iVar7 = iVar7 + -1;
                                  pbVar24 = pbVar25 + (uint)bVar28 * -2 + 1;
                                  bVar26 = *pbVar23 < *pbVar25;
                                  bVar27 = *pbVar23 == *pbVar25;
                                  pbVar23 = pbVar23 + (uint)bVar28 * -2 + 1;
                                  pbVar25 = pbVar24;
                                } while (bVar27);
                                uVar8 = (uint)(char)((!bVar26 && !bVar27) - bVar26);
                                if (uVar8 == 0) {
                                  local_104 = 0x2b;
                                  local_48 = ppbVar21;
                                }
                                else {
                                  uVar8 = strcmp((char *)pbVar1,"-EncryptedData_decrypt");
                                  if (uVar8 == 0) {
                                    local_104 = 0x2d;
                                    local_48 = ppbVar21;
                                  }
                                  else {
                                    uVar8 = strcmp((char *)pbVar1,"-EncryptedData_encrypt");
                                    if (uVar8 == 0) {
                                      local_104 = 0x1e;
                                      local_48 = ppbVar21;
                                    }
                                    else {
                                      iVar7 = strcmp((char *)pbVar1,"-des3");
                                      if (iVar7 == 0) {
                                        local_ac = EVP_des_ede3_cbc();
                                        uVar8 = local_40;
                                      }
                                      else {
                                        iVar7 = strcmp((char *)pbVar1,"-des");
                                        if (iVar7 == 0) {
                                          local_ac = EVP_des_cbc();
                                          uVar8 = local_40;
                                        }
                                        else {
                                          iVar7 = strcmp((char *)pbVar1,"-seed");
                                          if (iVar7 == 0) {
                                            local_ac = EVP_seed_cbc();
                                            uVar8 = local_40;
                                          }
                                          else {
                                            iVar7 = strcmp((char *)pbVar1,"-rc2-40");
                                            if (iVar7 == 0) {
                                              local_ac = EVP_rc2_40_cbc();
                                              uVar8 = local_40;
                                            }
                                            else {
                                              iVar7 = strcmp((char *)pbVar1,"-rc2-128");
                                              if (iVar7 == 0) {
                                                local_ac = EVP_rc2_cbc();
                                                uVar8 = local_40;
                                              }
                                              else {
                                                iVar7 = strcmp((char *)pbVar1,"-rc2-64");
                                                if (iVar7 == 0) {
                                                  local_ac = EVP_rc2_64_cbc();
                                                  uVar8 = local_40;
                                                }
                                                else {
                                                  iVar7 = strcmp((char *)pbVar1,"-aes128");
                                                  if (iVar7 == 0) {
                                                    local_ac = EVP_aes_128_cbc();
                                                    uVar8 = local_40;
                                                  }
                                                  else {
                                                    iVar7 = strcmp((char *)pbVar1,"-aes192");
                                                    if (iVar7 == 0) {
                                                      local_ac = EVP_aes_192_cbc();
                                                      uVar8 = local_40;
                                                    }
                                                    else {
                                                      iVar7 = strcmp((char *)pbVar1,"-aes256");
                                                      if (iVar7 == 0) {
                                                        local_ac = EVP_aes_256_cbc();
                                                        uVar8 = local_40;
                                                      }
                                                      else {
                                                        iVar7 = strcmp((char *)pbVar1,"-camellia128"
                                                                      );
                                                        if (iVar7 == 0) {
                                                          local_ac = EVP_camellia_128_cbc();
                                                          uVar8 = local_40;
                                                        }
                                                        else {
                                                          iVar7 = strcmp((char *)pbVar1,
                                                                         "-camellia192");
                                                          if (iVar7 == 0) {
                                                            local_ac = EVP_camellia_192_cbc();
                                                            uVar8 = local_40;
                                                          }
                                                          else {
                                                            iVar7 = strcmp((char *)pbVar1,
                                                                           "-camellia256");
                                                            if (iVar7 == 0) {
                                                              local_ac = EVP_camellia_256_cbc();
                                                              uVar8 = local_40;
                                                            }
                                                            else {
                                                              uVar8 = strcmp((char *)pbVar1,
                                                                             "-debug_decrypt");
                                                              if (uVar8 == 0) {
                                                                local_b4 = local_b4 | 0x20000;
                                                                local_48 = ppbVar21;
                                                              }
                                                              else {
                                                                uVar8 = strcmp((char *)pbVar1,
                                                                               "-text");
                                                                if (uVar8 == 0) {
                                                                  local_b4 = local_b4 | 1;
                                                                  local_48 = ppbVar21;
                                                                }
                                                                else {
                                                                  uVar8 = strcmp((char *)pbVar1,
                                                                                 "-nointern");
                                                                  if (uVar8 == 0) {
                                                                    local_b4 = local_b4 | 0x10;
                                                                    local_48 = ppbVar21;
                                                                  }
                                                                  else {
                                                                    iVar7 = strcmp((char *)pbVar1,
                                                                                   "-noverify");
                                                                    if ((iVar7 == 0) ||
                                                                       (iVar7 = strcmp((char *)
                                                  pbVar1,"-no_signer_cert_verify"), iVar7 == 0)) {
                                                    local_b4 = local_b4 | 0x20;
                                                    uVar8 = 0;
                                                    local_48 = ppbVar21;
                                                  }
                                                  else {
                                                    uVar8 = strcmp((char *)pbVar1,"-nocerts");
                                                    if (uVar8 == 0) {
                                                      local_b4 = local_b4 | 2;
                                                      local_48 = ppbVar21;
                                                    }
                                                    else {
                                                      uVar8 = strcmp((char *)pbVar1,"-noattr");
                                                      if (uVar8 == 0) {
                                                        local_b4 = local_b4 | 0x100;
                                                        local_48 = ppbVar21;
                                                      }
                                                      else {
                                                        uVar8 = strcmp((char *)pbVar1,"-nodetach");
                                                        if (uVar8 == 0) {
                                                          local_b4 = local_b4 & 0xffffffbf;
                                                          local_48 = ppbVar21;
                                                        }
                                                        else {
                                                          uVar8 = strcmp((char *)pbVar1,
                                                                         "-nosmimecap");
                                                          if (uVar8 == 0) {
                                                            local_b4 = local_b4 | 0x200;
                                                            local_48 = ppbVar21;
                                                          }
                                                          else {
                                                            uVar8 = strcmp((char *)pbVar1,"-binary")
                                                            ;
                                                            if (uVar8 == 0) {
                                                              local_b4 = local_b4 | 0x80;
                                                              local_48 = ppbVar21;
                                                            }
                                                            else {
                                                              uVar8 = strcmp((char *)pbVar1,"-keyid"
                                                                            );
                                                              if (uVar8 == 0) {
                                                                local_b4 = local_b4 | 0x10000;
                                                                local_48 = ppbVar21;
                                                              }
                                                              else {
                                                                uVar8 = strcmp((char *)pbVar1,
                                                                               "-nosigs");
                                                                if (uVar8 == 0) {
                                                                  local_b4 = local_b4 | 0xc;
                                                                  local_48 = ppbVar21;
                                                                }
                                                                else {
                                                                  uVar8 = strcmp((char *)pbVar1,
                                                                                                                                                                  
                                                  "-no_content_verify");
                                                  if (uVar8 == 0) {
                                                    local_b4 = local_b4 | 4;
                                                    local_48 = ppbVar21;
                                                  }
                                                  else {
                                                    uVar8 = strcmp((char *)pbVar1,"-no_attr_verify")
                                                    ;
                                                    if (uVar8 == 0) {
                                                      local_b4 = local_b4 | 8;
                                                      local_48 = ppbVar21;
                                                    }
                                                    else {
                                                      uVar8 = strcmp((char *)pbVar1,"-stream");
                                                      if ((uVar8 == 0) ||
                                                         (uVar8 = strcmp((char *)pbVar1,"-indef"),
                                                         uVar8 == 0)) {
                                                        local_b4 = local_b4 | 0x1000;
                                                        local_48 = ppbVar21;
                                                      }
                                                      else {
                                                        uVar8 = strcmp((char *)pbVar1,"-noindef");
                                                        if (uVar8 == 0) {
                                                          local_b4 = local_b4 & 0xffffefff;
                                                          local_48 = ppbVar21;
                                                        }
                                                        else {
                                                          uVar8 = strcmp((char *)pbVar1,"-nooldmime"
                                                                        );
                                                          if (uVar8 == 0) {
                                                            local_b4 = local_b4 | 0x400;
                                                            local_48 = ppbVar21;
                                                          }
                                                          else {
                                                            uVar8 = strcmp((char *)pbVar1,"-crlfeol"
                                                                          );
                                                            if (uVar8 == 0) {
                                                              local_b4 = local_b4 | 0x800;
                                                              local_48 = ppbVar21;
                                                            }
                                                            else {
                                                              uVar8 = strcmp((char *)pbVar1,"-noout"
                                                                            );
                                                              if (uVar8 == 0) {
LAB_0808b58e:
                                                                bVar3 = true;
                                                                local_48 = ppbVar21;
                                                              }
                                                              else {
                                                                uVar8 = strcmp((char *)pbVar1,
                                                                                                                                                              
                                                  "-receipt_request_print");
                                                  if (uVar8 == 0) {
                                                    bVar5 = true;
                                                    local_48 = ppbVar21;
                                                  }
                                                  else {
                                                    uVar8 = strcmp((char *)pbVar1,
                                                                   "-receipt_request_all");
                                                    if (uVar8 == 0) {
                                                      local_b0 = 0;
                                                      local_48 = ppbVar21;
                                                    }
                                                    else {
                                                      uVar8 = strcmp((char *)pbVar1,
                                                                     "-receipt_request_first");
                                                      if (uVar8 == 0) {
                                                        local_b0 = 1;
                                                        local_48 = ppbVar21;
                                                      }
                                                      else {
                                                        iVar7 = strcmp((char *)pbVar1,
                                                                       "-receipt_request_from");
                                                        if (iVar7 == 0) {
                                                          if (ppbVar21[1] == (byte *)0x0)
                                                          goto LAB_08088fc4;
                                                          local_48 = ppbVar21 + 1;
                                                          if (local_f4 == (_STACK *)0x0) {
                                                            local_f4 = sk_new_null();
                                                          }
                                                          sk_push(local_f4,*local_48);
                                                          uVar8 = local_40;
                                                        }
                                                        else {
                                                          iVar7 = strcmp((char *)pbVar1,
                                                                         "-receipt_request_to");
                                                          if (iVar7 == 0) {
                                                            if (ppbVar21[1] == (byte *)0x0)
                                                            goto LAB_08088fc4;
                                                            local_48 = ppbVar21 + 1;
                                                            if (local_100 == (_STACK *)0x0) {
                                                              local_100 = sk_new_null();
                                                            }
                                                            sk_push(local_100,*local_48);
                                                            uVar8 = local_40;
                                                          }
                                                          else {
                                                            uVar8 = strcmp((char *)pbVar1,"-print");
                                                            if (uVar8 == 0) {
                                                              bVar4 = true;
                                                              goto LAB_0808b58e;
                                                            }
                                                            iVar7 = strcmp((char *)pbVar1,
                                                                           "-secretkey");
                                                            if (iVar7 == 0) {
                                                              if (ppbVar21[1] == (byte *)0x0)
                                                              goto LAB_08088fc4;
                                                              local_48 = ppbVar21 + 1;
                                                              local_e4 = string_to_hex((char *)
                                                  ppbVar21[1],(long *)&local_24);
                                                  if (local_e4 == (uchar *)0x0) {
                                                    BIO_printf(bio_err,"Invalid key %s\n",*local_48,
                                                               ppbVar21);
                                                    goto LAB_08088fc4;
                                                  }
                                                  local_90 = local_24;
                                                  uVar8 = local_40;
                                                  }
                                                  else {
                                                    iVar7 = strcmp((char *)pbVar1,"-secretkeyid");
                                                    if (iVar7 == 0) {
                                                      if (ppbVar21[1] == (byte *)0x0)
                                                      goto LAB_08088fc4;
                                                      local_48 = ppbVar21 + 1;
                                                      local_cc = string_to_hex((char *)ppbVar21[1],
                                                                               (long *)&local_24);
                                                      if (local_cc == (uchar *)0x0) {
                                                        BIO_printf(bio_err,"Invalid id %s\n",
                                                                   *local_48,0);
                                                        goto LAB_08088fc4;
                                                      }
                                                      local_74 = local_24;
                                                      uVar8 = local_40;
                                                    }
                                                    else {
                                                      uVar8 = strcmp((char *)pbVar1,"-pwri_password"
                                                                    );
                                                      if (uVar8 == 0) {
                                                        local_98 = ppbVar21[1];
                                                        pbVar1 = local_98;
joined_r0x0808b681:
                                                        if (pbVar1 == (byte *)0x0)
                                                        goto LAB_08088fc4;
LAB_0808b687:
                                                        local_48 = ppbVar21 + 1;
                                                      }
                                                      else {
                                                        iVar7 = strcmp((char *)pbVar1,
                                                                       "-econtent_type");
                                                        if (iVar7 == 0) {
                                                          if (ppbVar21[1] == (byte *)0x0)
                                                          goto LAB_08088fc4;
                                                          local_48 = ppbVar21 + 1;
                                                          local_c0 = (X509_VERIFY_PARAM *)
                                                                     OBJ_txt2obj((char *)ppbVar21[1]
                                                                                 ,0);
                                                          uVar8 = local_40;
                                                          if (local_c0 == (X509_VERIFY_PARAM *)0x0)
                                                          {
                                                            BIO_printf(bio_err,"Invalid OID %s\n",
                                                                       *local_48,pbVar24);
                                                            goto LAB_08088fc4;
                                                          }
                                                        }
                                                        else {
                                                          uVar8 = strcmp((char *)pbVar1,"-rand");
                                                          if (uVar8 != 0) {
                                                            uVar8 = strcmp((char *)pbVar1,"-engine")
                                                            ;
                                                            if (uVar8 == 0) {
                                                              local_d8 = (EVP_PKEY *)ppbVar21[1];
                                                              pbVar1 = (byte *)local_d8;
                                                            }
                                                            else {
                                                              uVar8 = strcmp((char *)pbVar1,
                                                                             "-passin");
                                                              if (uVar8 == 0) {
                                                                local_dc = (X509_STORE *)ppbVar21[1]
                                                                ;
                                                                pbVar1 = (byte *)local_dc;
                                                              }
                                                              else {
                                                                uVar22 = (uint)pbVar1[1];
                                                                if (((uVar22 == 0x74) &&
                                                                    (pbVar1[2] == 0x6f)) &&
                                                                   (pbVar1[3] == 0)) {
                                                                  local_68 = ppbVar21[1];
                                                                  pbVar1 = local_68;
joined_r0x0808b7c6:
                                                                  if (pbVar1 != (byte *)0x0) {
                                                                    uVar8 = 0;
                                                                    local_48 = ppbVar21 + 1;
                                                                    goto LAB_08088ee8;
                                                                  }
                                                                  goto LAB_08088fc4;
                                                                }
                                                                uVar8 = strcmp((char *)pbVar1,
                                                                               "-from");
                                                                if (uVar8 == 0) {
                                                                  local_64 = ppbVar21[1];
                                                                  pbVar1 = local_64;
                                                                }
                                                                else {
                                                                  uVar8 = strcmp((char *)pbVar1,
                                                                                 "-subject");
                                                                  if (uVar8 == 0) {
                                                                    local_60 = ppbVar21[1];
                                                                    pbVar1 = local_60;
                                                                  }
                                                                  else {
                                                                    iVar7 = strcmp((char *)pbVar1,
                                                                                   "-signer");
                                                                    if (iVar7 == 0) {
                                                                      if (ppbVar21[1] != (byte *)0x0
                                                                         ) {
                                                                        if (local_b8 != (byte *)0x0)
                                                                        {
                                                                          if (local_fc ==
                                                                              (_STACK *)0x0) {
                                                                            local_fc = sk_new_null()
                                                                            ;
                                                                          }
                                                                          sk_push(local_fc,local_b8)
                                                                          ;
                                                                          if (local_ec == (BIO *)0x0
                                                                             ) {
                                                                            local_ec = (BIO *)
                                                  local_b8;
                                                  }
                                                  if (local_f8 == (_STACK *)0x0) {
                                                    local_f8 = sk_new_null();
                                                  }
                                                  sk_push(local_f8,local_ec);
                                                  local_ec = (BIO *)0x0;
                                                  ppbVar21 = local_48;
                                                  }
                                                  local_b8 = ppbVar21[1];
                                                  uVar8 = local_40;
                                                  local_48 = ppbVar21 + 1;
                                                  goto LAB_08088ee8;
                                                  }
                                                  goto LAB_08088fc4;
                                                  }
                                                  uVar8 = strcmp((char *)pbVar1,"-recip");
                                                  if (uVar8 == 0) {
                                                    local_e8 = (BIO *)ppbVar21[1];
                                                    pbVar1 = (byte *)local_e8;
                                                  }
                                                  else {
                                                    uVar8 = strcmp((char *)pbVar1,"-certsout");
                                                    if (uVar8 == 0) {
                                                      local_8c = ppbVar21[1];
                                                      pbVar1 = local_8c;
                                                    }
                                                    else {
                                                      if (((uVar22 == 0x6d) && (pbVar1[2] == 100))
                                                         && (pbVar1[3] == 0)) {
                                                        if (ppbVar21[1] != (byte *)0x0) {
                                                          local_48 = ppbVar21 + 1;
                                                          local_78 = EVP_get_digestbyname
                                                                               ((char *)ppbVar21[1])
                                                          ;
                                                          uVar8 = local_40;
                                                          if (local_78 != (EVP_MD *)0x0)
                                                          goto LAB_08088ee8;
                                                          BIO_printf(bio_err,"Unknown digest %s\n",
                                                                     *local_48,pbVar24);
                                                        }
                                                        goto LAB_08088fc4;
                                                      }
                                                      iVar7 = strcmp((char *)pbVar1,"-inkey");
                                                      if (iVar7 == 0) {
                                                        if (ppbVar21[1] == (byte *)0x0)
                                                        goto LAB_08088fc4;
                                                        if (local_ec != (BIO *)0x0) {
                                                          if (local_b8 == (byte *)0x0)
                                                          goto LAB_0808997e;
                                                          if (local_fc == (_STACK *)0x0) {
                                                            local_fc = sk_new_null();
                                                          }
                                                          sk_push(local_fc,local_b8);
                                                          if (local_f8 == (_STACK *)0x0) {
                                                            local_f8 = sk_new_null();
                                                          }
                                                          sk_push(local_f8,local_ec);
                                                          local_b8 = (byte *)0x0;
                                                          ppbVar21 = local_48;
                                                        }
                                                        local_ec = (BIO *)ppbVar21[1];
                                                        uVar8 = local_40;
                                                        local_48 = ppbVar21 + 1;
                                                        goto LAB_08088ee8;
                                                      }
                                                      pcVar30 = "-keyform";
                                                      iVar13 = iVar7;
                                                      iVar18 = strcmp((char *)pbVar1,"-keyform");
                                                      if (iVar18 == 0) {
                                                        if (ppbVar21[1] == (byte *)0x0)
                                                        goto LAB_08088fc4;
                                                        local_48 = ppbVar21 + 1;
                                                        local_94 = str2fmt(ppbVar21[1],pcVar30,iVar7
                                                                           ,iVar13);
                                                        uVar8 = local_40;
                                                        goto LAB_08088ee8;
                                                      }
                                                      pcVar30 = "-rctform";
                                                      iVar7 = iVar18;
                                                      iVar13 = strcmp((char *)pbVar1,"-rctform");
                                                      if (iVar13 == 0) {
                                                        if (ppbVar21[1] == (byte *)0x0)
                                                        goto LAB_08088fc4;
                                                        local_48 = ppbVar21 + 1;
                                                        local_88 = str2fmt(ppbVar21[1],pcVar30,
                                                                           iVar18,iVar7);
                                                        uVar8 = local_40;
                                                        goto LAB_08088ee8;
                                                      }
                                                      uVar8 = strcmp((char *)pbVar1,"-certfile");
                                                      if (uVar8 == 0) {
                                                        local_e0 = (CMS_ContentInfo *)ppbVar21[1];
                                                        pbVar1 = (byte *)local_e0;
                                                        goto joined_r0x0808b76a;
                                                      }
                                                      uVar8 = strcmp((char *)pbVar1,"-CAfile");
                                                      if (uVar8 == 0) {
                                                        local_5c = ppbVar21[1];
                                                        pbVar1 = local_5c;
                                                        goto joined_r0x0808b76a;
                                                      }
                                                      uVar8 = strcmp((char *)pbVar1,"-CApath");
                                                      if (uVar8 == 0) {
                                                        local_58 = ppbVar21[1];
                                                        pbVar1 = local_58;
                                                        goto joined_r0x0808b681;
                                                      }
                                                      if (((uVar22 == 0x69) && (pbVar1[2] == 0x6e))
                                                         && (pbVar1[3] == 0)) {
                                                        local_9c = ppbVar21[1];
                                                        pbVar1 = local_9c;
                                                        goto joined_r0x0808b7c6;
                                                      }
                                                      pcVar30 = "-inform";
                                                      uVar32 = uVar8;
                                                      iVar7 = strcmp((char *)pbVar1,"-inform");
                                                      if (iVar7 == 0) {
                                                        if (ppbVar21[1] == (byte *)0x0)
                                                        goto LAB_08088fc4;
                                                        local_48 = ppbVar21 + 1;
                                                        local_d4 = (BIO *)str2fmt(ppbVar21[1],
                                                                                  pcVar30,uVar8,
                                                                                  uVar32);
                                                        uVar8 = local_40;
                                                        goto LAB_08088ee8;
                                                      }
                                                      pcVar30 = "-outform";
                                                      pbVar23 = pbVar24;
                                                      iVar7 = strcmp((char *)pbVar1,"-outform");
                                                      if (iVar7 == 0) {
                                                        if (ppbVar21[1] != (byte *)0x0) {
                                                          local_48 = ppbVar21 + 1;
                                                          local_a4 = str2fmt(ppbVar21[1],pcVar30,
                                                                             pbVar24,pbVar23);
                                                          uVar8 = local_40;
                                                          goto LAB_08088ee8;
                                                        }
                                                        goto LAB_08088fc4;
                                                      }
                                                      uVar8 = strcmp((char *)pbVar1,"-out");
                                                      if (uVar8 == 0) {
                                                        local_84 = ppbVar21[1];
                                                        pbVar1 = local_84;
                                                        goto joined_r0x0808b76a;
                                                      }
                                                      pcVar30 = "-content";
                                                      uVar32 = uVar22;
                                                      uVar8 = strcmp((char *)pbVar1,"-content");
                                                      if (uVar8 != 0) {
                                                        iVar7 = args_verify(&local_48,0,&local_40,
                                                                            bio_err,&local_38,
                                                                            pcVar30,uVar22,uVar32);
                                                        if (iVar7 == 0) {
                                                          local_ac = EVP_get_cipherbyname
                                                                               ((char *)(*local_48 +
                                                                                        1));
                                                          uVar8 = local_40;
                                                          if (local_ac == (EVP_CIPHER *)0x0) {
                                                            local_40 = 1;
                                                            uVar8 = 1;
                                                          }
                                                          goto LAB_08088ee8;
                                                        }
                                                        goto LAB_08088ae0;
                                                      }
                                                      local_80 = ppbVar21[1];
                                                      pbVar1 = local_80;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
joined_r0x0808b76a:
                                                  if (pbVar1 != (byte *)0x0) goto LAB_0808b687;
                                                  goto LAB_08088fc4;
                                                  }
                                                  local_d0 = (X509 *)ppbVar21[1];
                                                  if (local_d0 == (X509 *)0x0) goto LAB_08088fc4;
                                                  bVar2 = true;
                                                  local_48 = ppbVar21 + 1;
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
LAB_08088ee8:
    local_48 = local_48 + 1;
    if (uVar8 != 0) goto LAB_08088efa;
    goto LAB_08088af0;
  }
LAB_08088efa:
  if ((local_b0 != -1 || local_f4 != (_STACK *)0x0) && local_100 == (_STACK *)0x0) {
    BIO_puts(bio_err,"No Signed Receipts Recipients\n");
    local_100 = (_STACK *)0x0;
LAB_08088fc4:
    BIO_printf(bio_err,"Usage cms [options] cert.pem ...\n");
    BIO_printf(bio_err,"where options are\n");
    BIO_printf(bio_err,"-encrypt       encrypt message\n");
    BIO_printf(bio_err,"-decrypt       decrypt encrypted message\n");
    BIO_printf(bio_err,"-sign          sign message\n");
    BIO_printf(bio_err,"-verify        verify signed message\n");
    BIO_printf(bio_err,"-cmsout        output CMS structure\n");
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
    BIO_printf(bio_err,"-certsout file certificate output file\n");
    BIO_printf(bio_err,"-signer file   signer certificate file\n");
    BIO_printf(bio_err,"-recip  file   recipient certificate file for decryption\n");
    BIO_printf(bio_err,"-keyid         use subject key identifier\n");
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
               "-crl_check_all check revocation status of signer\'s certificate chain using CRLs\n")
    ;
    BIO_printf(bio_err,"-engine e      use engine e, possibly a hardware device.\n");
    BIO_printf(bio_err,"-passin arg    input file pass phrase source\n");
    BIO_printf(bio_err,"-rand file%cfile%c...\n",0x3a,0x3a);
    BIO_printf(bio_err,"               load the file (or the files in the directory) into\n");
    BIO_printf(bio_err,"               the random number generator\n");
    pcVar30 = "cert.pem       recipient certificate(s) for encryption\n";
LAB_08089341:
    pass = (EVP_PKEY *)0x0;
    a = (CMS_ReceiptRequest *)0x0;
    cms = (EVP_PKEY *)0x0;
    iVar7 = 1;
    BIO_printf(bio_err,pcVar30);
    local_d4 = (BIO *)0x0;
    local_ec = (BIO *)0x0;
    local_e8 = (BIO *)0x0;
    local_c8 = (_STACK *)0x0;
    local_bc = (_STACK *)0x0;
    local_d8 = (EVP_PKEY *)0x0;
    local_d0 = (X509 *)0x0;
    local_c4 = (X509 *)0x0;
    local_dc = (X509_STORE *)0x0;
    local_e0 = (CMS_ContentInfo *)0x0;
  }
  else {
    pass = (EVP_PKEY *)(local_104 & 0x40);
    if (pass != (EVP_PKEY *)0x0) {
      if ((local_ec == (BIO *)0x0) || (local_b8 != (byte *)0x0)) {
        if (local_b8 != (byte *)0x0) {
          if (local_fc == (_STACK *)0x0) {
            local_fc = sk_new_null();
          }
          sk_push(local_fc,local_b8);
          if (local_f8 == (_STACK *)0x0) {
            local_f8 = sk_new_null();
          }
          if (local_ec != (BIO *)0x0) {
            local_b8 = (byte *)local_ec;
          }
          sk_push(local_f8,local_b8);
        }
        if (local_fc == (_STACK *)0x0) {
          BIO_printf(bio_err,"No signer certificate specified\n");
          bVar2 = true;
          goto LAB_080896b9;
        }
        bVar2 = true;
        local_ec = (BIO *)0x0;
        local_b8 = (byte *)0x0;
        uVar8 = local_40;
        goto LAB_08088fbc;
      }
LAB_0808997e:
      BIO_puts(bio_err,"Illegal -inkey without -signer\n");
      goto LAB_08088fc4;
    }
    if ((local_100 != (_STACK *)0x0) || (local_f4 != (_STACK *)0x0)) {
      BIO_puts(bio_err,"Signed receipts only allowed with -sign\n");
      goto LAB_08088fc4;
    }
    if ((local_f8 != (_STACK *)0x0) || (local_fc != (_STACK *)0x0)) {
      BIO_puts(bio_err,"Multiple signers or keys not allowed\n");
      local_f4 = (_STACK *)0x0;
      local_100 = (_STACK *)0x0;
      goto LAB_08088fc4;
    }
    if (local_104 != 0x22) {
      if (local_104 == 0x11) {
        if (((*local_48 != (byte *)0x0) || (local_e4 != (uchar *)0x0)) || (local_98 != (byte *)0x0))
        {
          bVar2 = true;
          local_f8 = (_STACK *)0x0;
          local_fc = (_STACK *)0x0;
          goto LAB_08088fbc;
        }
        BIO_printf(bio_err,"No recipient(s) certificate(s) specified\n");
        bVar2 = true;
        local_f8 = (_STACK *)0x0;
      }
      else {
        if (local_104 != 0) goto LAB_080896e9;
        local_f8 = (_STACK *)0x0;
      }
LAB_080896b9:
      local_40 = 1;
      local_fc = (_STACK *)0x0;
      goto LAB_08088fc4;
    }
    if ((local_e8 == (BIO *)0x0) && (local_ec == (BIO *)0x0)) {
      if ((local_e4 == (uchar *)0x0) && (local_98 == (byte *)0x0)) {
        BIO_printf(bio_err,"No recipient certificate or key specified\n");
        local_f8 = (_STACK *)0x0;
        goto LAB_080896b9;
      }
      local_ec = (BIO *)0x0;
      local_f8 = (_STACK *)0x0;
      local_fc = (_STACK *)0x0;
    }
    else {
LAB_080896e9:
      local_f8 = (_STACK *)0x0;
      local_fc = (_STACK *)0x0;
    }
LAB_08088fbc:
    if (uVar8 != 0) goto LAB_08088fc4;
    pcVar30 = (char *)0x0;
    uVar9 = setup_engine(bio_err,local_d8,0);
    iVar7 = app_passwd(bio_err,local_dc,0,&local_3c,0);
    if (iVar7 == 0) {
      pcVar30 = "Error getting password\n";
      goto LAB_08089341;
    }
    if (bVar2) {
      pcVar30 = (char *)(uint)(local_d0 != (X509 *)0x0);
      app_RAND_load_file(0,bio_err,pcVar30);
      if (local_d0 != (X509 *)0x0) {
        pcVar30 = (char *)app_RAND_load_files(local_d0);
        BIO_printf(bio_err,"%ld semi-random bytes loaded\n",pcVar30);
      }
    }
    uVar22 = local_b4 & 0xffffffbf;
    if (pass != (EVP_PKEY *)0x0) {
      uVar22 = local_b4;
    }
    if ((local_104 & 0x10) == 0) {
      if ((uVar22 & 0x80) == 0) {
        if ((local_104 & 0x20) == 0) {
          local_dc = (X509_STORE *)&DAT_081efd1c;
          mode = "r";
          goto LAB_08089a18;
        }
        local_dc = (X509_STORE *)&DAT_081efd1c;
        goto LAB_080897dd;
      }
      if ((local_104 & 0x20) != 0) {
        local_dc = (X509_STORE *)&DAT_081ea846;
        goto LAB_080897dd;
      }
      local_dc = (X509_STORE *)&DAT_081ea846;
      mode = "rb";
LAB_08089a18:
      if (local_104 != 0x11) goto LAB_080897f1;
      if (local_ac == (EVP_CIPHER *)0x0) {
        local_ac = EVP_des_ede3_cbc();
      }
      if ((local_e4 != (uchar *)0x0) && (local_cc == (uchar *)0x0)) {
        BIO_printf(bio_err,"No secret key id\n",pcVar30);
        local_cc = (uchar *)0x0;
        local_c8 = (_STACK *)0x0;
        local_bc = (_STACK *)0x0;
        goto LAB_08089a91;
      }
      if (*local_48 == (byte *)0x0) goto LAB_080897f1;
      local_bc = sk_new_null();
      pbVar1 = *local_48;
      while (pbVar1 != (byte *)0x0) {
        pvVar16 = (void *)load_cert(bio_err,pbVar1,3,0,uVar9,"recipient certificate file");
        if (pvVar16 == (void *)0x0) {
          local_c8 = (_STACK *)0x0;
          goto LAB_08089a91;
        }
        sk_push(local_bc,pvVar16);
        pbVar1 = local_48[1];
        local_48 = local_48 + 1;
      }
      if (local_e0 != (CMS_ContentInfo *)0x0) goto LAB_08089805;
      local_c8 = (_STACK *)0x0;
LAB_0808986b:
      bVar26 = local_104 == 0x53 || local_104 == 0x3f;
      if (bVar26) {
        bVar26 = false;
        local_d0 = (X509 *)0x0;
LAB_08089d1d:
        local_c4 = (X509 *)0x0;
        if (local_ec == (BIO *)0x0) {
          local_ec = (BIO *)local_b8;
          goto LAB_08089d39;
        }
        goto LAB_08089c98;
      }
      local_d0 = (X509 *)0x0;
      local_c4 = (X509 *)0x0;
      local_d8 = (EVP_PKEY *)0x0;
    }
    else {
      local_dc = (X509_STORE *)&DAT_081efd1c;
      if (local_a4 == 1) {
        local_dc = (X509_STORE *)&DAT_081ea846;
      }
      if ((local_104 & 0x20) == 0) {
        mode = "r";
        if ((uVar22 & 0x80) != 0) {
          mode = "rb";
        }
        goto LAB_08089a18;
      }
LAB_080897dd:
      uVar8 = local_104 & 0x20;
      mode = "r";
      if (local_d4 == (BIO *)0x1) {
        mode = "rb";
      }
LAB_080897f1:
      local_bc = (_STACK *)0x0;
      if (local_e0 != (CMS_ContentInfo *)0x0) {
LAB_08089805:
        local_c8 = (_STACK *)load_certs(bio_err,local_e0,3,0,uVar9,"certificate file");
        if (local_c8 != (_STACK *)0x0) goto LAB_08089836;
        ERR_print_errors(bio_err);
LAB_08089a91:
        local_d0 = (X509 *)0x0;
LAB_08089aa1:
        local_d4 = (BIO *)0x0;
        local_d8 = (EVP_PKEY *)0x0;
        local_e8 = (BIO *)0x0;
        local_ec = (BIO *)0x0;
        a = (CMS_ReceiptRequest *)0x0;
        pass = (EVP_PKEY *)0x0;
        local_c4 = (X509 *)0x0;
        local_dc = (X509_STORE *)0x0;
        cms = (EVP_PKEY *)0x0;
        local_e0 = (CMS_ContentInfo *)0x0;
        iVar7 = 2;
        goto LAB_0808946b;
      }
      local_c8 = (_STACK *)0x0;
LAB_08089836:
      bVar26 = local_104 == 0x22;
      if ((local_e8 == (BIO *)0x0) || (!bVar26)) {
        if (local_104 == 0x3f) {
          local_d0 = (X509 *)load_cert(bio_err,local_b8,3,0,uVar9,"receipt signer certificate file")
          ;
          if (local_d0 != (X509 *)0x0) goto LAB_08089d1d;
          ERR_print_errors(bio_err);
          goto LAB_08089aa1;
        }
        if (local_104 != 0x22) goto LAB_0808986b;
        local_c4 = (X509 *)0x0;
      }
      else {
        local_c4 = (X509 *)load_cert(bio_err,local_e8,3,0,uVar9,"recipient certificate file");
        if (local_c4 == (X509 *)0x0) {
          pass = (EVP_PKEY *)0x0;
          a = (CMS_ReceiptRequest *)0x0;
          cms = (EVP_PKEY *)0x0;
          iVar7 = 2;
          ERR_print_errors(bio_err);
          local_d4 = (BIO *)0x0;
          local_ec = (BIO *)0x0;
          local_e8 = (BIO *)0x0;
          local_d8 = (EVP_PKEY *)0x0;
          local_d0 = (X509 *)0x0;
          local_dc = (X509_STORE *)0x0;
          local_e0 = (CMS_ContentInfo *)0x0;
          goto LAB_0808946b;
        }
      }
      if (local_ec == (BIO *)0x0) {
        local_ec = local_e8;
        bVar26 = true;
        local_d0 = (X509 *)0x0;
LAB_08089d39:
        if (local_ec == (BIO *)0x0) {
          local_d8 = (EVP_PKEY *)0x0;
          goto LAB_080898a2;
        }
      }
      else {
        bVar26 = true;
        local_d0 = (X509 *)0x0;
      }
LAB_08089c98:
      pcVar30 = "signing key file";
      local_d8 = (EVP_PKEY *)load_key(bio_err,local_ec,local_94,0,local_3c,uVar9,"signing key file")
      ;
      if (local_d8 == (EVP_PKEY *)0x0) {
        pass = (EVP_PKEY *)0x0;
        a = (CMS_ReceiptRequest *)0x0;
        local_d4 = (BIO *)0x0;
        local_ec = (BIO *)0x0;
        local_e8 = (BIO *)0x0;
        cms = (EVP_PKEY *)0x0;
        local_dc = (X509_STORE *)0x0;
        local_e0 = (CMS_ContentInfo *)0x0;
        iVar7 = 2;
        goto LAB_0808946b;
      }
    }
LAB_080898a2:
    if (local_9c != (byte *)0x0) {
      local_e8 = BIO_new_file((char *)local_9c,mode);
      if (local_e8 != (BIO *)0x0) goto LAB_080898c7;
      pcVar30 = "Can\'t open input file %s\n";
LAB_080898f8:
      pass = (EVP_PKEY *)0x0;
      a = (CMS_ReceiptRequest *)0x0;
      cms = (EVP_PKEY *)0x0;
      iVar7 = 2;
      BIO_printf(bio_err,pcVar30,local_9c);
      local_d4 = (BIO *)0x0;
      local_ec = (BIO *)0x0;
      local_dc = (X509_STORE *)0x0;
      local_e0 = (CMS_ContentInfo *)0x0;
      goto LAB_0808946b;
    }
    local_e8 = BIO_new_fp(stdin,0);
LAB_080898c7:
    local_9c = (byte *)pcVar30;
    if (uVar8 != 0) {
      if (local_d4 == (BIO *)0x6) {
        cms = (EVP_PKEY *)SMIME_read_CMS(local_e8,&local_44);
      }
      else if (local_d4 == (BIO *)0x3) {
        local_9c = (byte *)0x0;
        cms = (EVP_PKEY *)
              PEM_read_bio_CMS(local_e8,(CMS_ContentInfo **)0x0,(undefined1 *)0x0,(void *)0x0);
      }
      else {
        if (local_d4 != (BIO *)0x1) {
          pcVar30 = "Bad input format for CMS file\n";
          goto LAB_080898f8;
        }
        cms = (EVP_PKEY *)d2i_CMS_bio(local_e8,(CMS_ContentInfo **)0x0);
      }
      if (cms != (EVP_PKEY *)0x0) {
        if (local_80 != (byte *)0x0) {
          BIO_free(local_44);
          local_44 = BIO_new_file((char *)local_80,"rb");
          if (local_44 == (BIO *)0x0) {
            pcVar30 = "Can\'t read content file %s\n";
            local_9c = local_80;
            goto LAB_0808a00d;
          }
        }
        if (local_8c != (byte *)0x0) {
          p_Var11 = (_STACK *)CMS_get1_certs((CMS_ContentInfo *)cms);
          pBVar12 = BIO_new_file((char *)local_8c,"w");
          if (pBVar12 == (BIO *)0x0) {
            pass = (EVP_PKEY *)0x0;
            a = (CMS_ReceiptRequest *)0x0;
            iVar7 = 5;
            BIO_printf(bio_err,"Error writing certs to %s\n",local_8c);
            local_d4 = (BIO *)0x0;
            local_ec = (BIO *)0x0;
            local_dc = (X509_STORE *)0x0;
            local_e0 = (CMS_ContentInfo *)0x0;
            goto LAB_0808946b;
          }
          for (iVar7 = 0; iVar13 = sk_num(p_Var11), iVar7 < iVar13; iVar7 = iVar7 + 1) {
            pXVar15 = (X509 *)sk_value(p_Var11,iVar7);
            PEM_write_bio_X509(pBVar12,pXVar15);
          }
          BIO_free(pBVar12);
          sk_pop_free(p_Var11,X509_free);
        }
        goto LAB_08089b99;
      }
      pcVar30 = "Error reading S/MIME message\n";
LAB_0808a00d:
      pass = (EVP_PKEY *)0x0;
      a = (CMS_ReceiptRequest *)0x0;
      iVar7 = 2;
      BIO_printf(bio_err,pcVar30,local_9c);
      local_d4 = (BIO *)0x0;
      local_ec = (BIO *)0x0;
      local_dc = (X509_STORE *)0x0;
      local_e0 = (CMS_ContentInfo *)0x0;
      goto LAB_0808946b;
    }
    cms = (EVP_PKEY *)0x0;
LAB_08089b99:
    if (local_a0 == (byte *)0x0) {
      local_d4 = (BIO *)0x0;
      local_e0 = (CMS_ContentInfo *)0x0;
    }
    else {
      if (local_88 == 1) {
        local_d4 = BIO_new_file((char *)local_a0,"rb");
        if (local_d4 == (BIO *)0x0) goto LAB_0808a001;
        local_e0 = d2i_CMS_bio(local_d4,(CMS_ContentInfo **)0x0);
      }
      else {
        local_d4 = BIO_new_file((char *)local_a0,"r");
        if (local_d4 == (BIO *)0x0) {
LAB_0808a001:
          pcVar30 = "Can\'t open receipt file %s\n";
          local_9c = local_a0;
          goto LAB_0808a00d;
        }
        if (local_88 == 6) {
          local_e0 = SMIME_read_CMS(local_d4,(BIO **)0x0);
        }
        else {
          if (local_88 != 3) {
            pass = (EVP_PKEY *)0x0;
            a = (CMS_ReceiptRequest *)0x0;
            iVar7 = 2;
            BIO_printf(bio_err,"Bad input format for receipt\n");
            local_ec = (BIO *)0x0;
            local_dc = (X509_STORE *)0x0;
            local_e0 = (CMS_ContentInfo *)0x0;
            goto LAB_0808946b;
          }
          local_9c = (byte *)0x0;
          local_e0 = PEM_read_bio_CMS(local_d4,(CMS_ContentInfo **)0x0,(undefined1 *)0x0,(void *)0x0
                                     );
        }
      }
      if (local_e0 == (CMS_ContentInfo *)0x0) {
        pass = (EVP_PKEY *)0x0;
        a = (CMS_ReceiptRequest *)0x0;
        iVar7 = 2;
        BIO_printf(bio_err,"Error reading receipt\n");
        local_ec = (BIO *)0x0;
        local_dc = (X509_STORE *)0x0;
        goto LAB_0808946b;
      }
    }
    if (local_84 == (byte *)0x0) {
      pcVar31 = (code *)0x0;
      local_ec = BIO_new_fp(stdout,0);
      uVar19 = extraout_ECX_04;
      uVar20 = extraout_EDX_04;
    }
    else {
      local_ec = BIO_new_file((char *)local_84,(char *)local_dc);
      uVar19 = extraout_ECX;
      uVar20 = extraout_EDX;
      pcVar31 = (code *)local_dc;
      if (local_ec == (BIO *)0x0) {
        pass = (EVP_PKEY *)0x0;
        a = (CMS_ReceiptRequest *)0x0;
        iVar7 = 2;
        BIO_printf(bio_err,"Can\'t open output file %s\n",local_84);
        local_dc = (X509_STORE *)0x0;
        goto LAB_0808946b;
      }
    }
    if ((local_104 == 0x24) || (local_dc = (X509_STORE *)0x0, local_104 == 0x30)) {
      local_dc = (X509_STORE *)setup_verify(bio_err,local_5c,local_58);
      if (local_dc == (X509_STORE *)0x0) {
        pass = (EVP_PKEY *)0x0;
        a = (CMS_ReceiptRequest *)0x0;
        iVar7 = 2;
        goto LAB_0808946b;
      }
      pcVar31 = cms_cb;
      X509_STORE_set_verify_cb(local_dc,cms_cb);
      uVar19 = extraout_ECX_02;
      uVar20 = extraout_EDX_02;
      local_9c = local_58;
      if (local_38 != (X509_VERIFY_PARAM *)0x0) {
        pcVar31 = (code *)local_38;
        X509_STORE_set1_param(local_dc,local_38);
        uVar19 = extraout_ECX_03;
        uVar20 = extraout_EDX_03;
        local_9c = local_58;
      }
    }
    local_b4 = uVar22;
    if (local_104 == 0x18) {
      a = (CMS_ReceiptRequest *)0x0;
      cms = (EVP_PKEY *)CMS_data_create(local_e8,uVar22);
      uVar19 = extraout_ECX_05;
      uVar20 = extraout_EDX_05;
LAB_0808a3c6:
      if (cms == (EVP_PKEY *)0x0) {
        pass = (EVP_PKEY *)0x0;
        iVar7 = 3;
        BIO_printf(bio_err,"Error creating CMS structure\n");
        goto LAB_0808946b;
      }
      if (bVar26) {
        if ((local_b4 & 0x20000) != 0) {
          CMS_decrypt((CMS_ContentInfo *)cms,(EVP_PKEY *)0x0,(X509 *)0x0,(BIO *)0x0,(BIO *)0x0,
                      local_b4);
        }
        if ((local_e4 == (uchar *)0x0) ||
           (iVar7 = CMS_decrypt_set1_key
                              ((CMS_ContentInfo *)cms,local_e4,(size_t)local_90,local_cc,
                               (size_t)local_74), iVar7 != 0)) {
          if ((local_d8 == (EVP_PKEY *)0x0) ||
             (iVar7 = CMS_decrypt_set1_pkey((CMS_ContentInfo *)cms,local_d8,local_c4), iVar7 != 0))
          {
            if ((local_98 == (byte *)0x0) ||
               (iVar7 = CMS_decrypt_set1_password((CMS_ContentInfo *)cms,local_98,-1), iVar7 != 0))
            {
              pEVar17 = (EVP_PKEY *)
                        CMS_decrypt((CMS_ContentInfo *)cms,(EVP_PKEY *)0x0,(X509 *)0x0,local_44,
                                    local_ec,local_b4);
              if (pEVar17 != (EVP_PKEY *)0x0) goto LAB_0808a43e;
              pcVar30 = "Error decrypting CMS structure\n";
              goto LAB_0808a65c;
            }
            pcVar30 = "Error decrypting CMS using password\n";
          }
          else {
            pcVar30 = "Error decrypting CMS using private key\n";
          }
        }
        else {
          pcVar30 = "Error decrypting CMS using secret key\n";
        }
        pass = (EVP_PKEY *)0x0;
        iVar7 = 4;
        BIO_puts(bio_err,pcVar30);
      }
      else {
        if (local_104 == 0x27) {
          pass = (EVP_PKEY *)0x0;
          iVar7 = CMS_data((CMS_ContentInfo *)cms,local_ec,local_b4);
          if (iVar7 != 0) {
            iVar7 = 0;
            goto LAB_0808947c;
          }
        }
        else if (local_104 == 0x2b) {
          pass = (EVP_PKEY *)0x0;
          iVar7 = CMS_uncompress((CMS_ContentInfo *)cms,local_44,local_ec,local_b4);
          if (iVar7 != 0) {
            iVar7 = 0;
            goto LAB_0808947c;
          }
        }
        else if (local_104 == 0x29) {
          pEVar17 = (EVP_PKEY *)CMS_digest_verify((CMS_ContentInfo *)cms,local_44,local_ec,local_b4)
          ;
joined_r0x0808ae36:
          if (0 < (int)pEVar17) {
            pass = (EVP_PKEY *)0x0;
            iVar7 = 0;
            BIO_printf(bio_err,"Verification successful\n",pEVar17,pEVar17);
            goto LAB_0808947c;
          }
          pcVar30 = "Verification failure\n";
LAB_0808a65c:
          BIO_printf(bio_err,pcVar30,pEVar17,pEVar17);
        }
        else if (local_104 == 0x2d) {
          pass = (EVP_PKEY *)0x0;
          iVar7 = CMS_EncryptedData_decrypt
                            ((CMS_ContentInfo *)cms,local_e4,(size_t)local_90,local_44,local_ec,
                             local_b4);
          if (iVar7 != 0) {
            iVar7 = 0;
            goto LAB_0808947c;
          }
        }
        else {
          if (local_104 != 0x24) {
            if (local_104 != 0x30) goto LAB_0808a41e;
            pEVar17 = (EVP_PKEY *)
                      CMS_verify_receipt(local_e0,(CMS_ContentInfo *)cms,(stack_st_X509 *)local_c8,
                                         local_dc,local_b4);
            goto joined_r0x0808ae36;
          }
          iVar7 = CMS_verify((CMS_ContentInfo *)cms,(stack_st_X509 *)local_c8,local_dc,local_44,
                             local_ec,local_b4);
          if (0 < iVar7) {
            BIO_printf(bio_err,"Verification successful\n",iVar7,iVar7);
            if (local_b8 != (byte *)0x0) {
              p_Var11 = (_STACK *)CMS_get0_signers((CMS_ContentInfo *)cms);
              pBVar12 = BIO_new_file((char *)local_b8,"w");
              if (pBVar12 == (BIO *)0x0) {
                pass = (EVP_PKEY *)0x0;
                iVar7 = 5;
                BIO_printf(bio_err,"Error writing signers to %s\n",local_b8,extraout_EDX_16);
                goto LAB_0808946b;
              }
              for (iVar7 = 0; iVar13 = sk_num(p_Var11), iVar7 < iVar13; iVar7 = iVar7 + 1) {
                pXVar15 = (X509 *)sk_value(p_Var11,iVar7);
                PEM_write_bio_X509(pBVar12,pXVar15);
              }
              BIO_free(pBVar12);
              sk_free(p_Var11);
            }
            pBVar12 = bio_err;
            if (bVar5) {
              p_Var11 = (_STACK *)CMS_get0_SignerInfos((CMS_ContentInfo *)cms);
              iVar7 = 0;
              while (iVar13 = sk_num(p_Var11), iVar7 < iVar13) {
                iVar13 = iVar7 + 1;
                uVar9 = extraout_ECX_14;
                uVar19 = extraout_ECX_14;
                pvVar16 = sk_value(p_Var11,iVar7);
                iVar7 = CMS_get1_ReceiptRequest(pvVar16,&local_34,uVar9,uVar19);
                BIO_printf(bio_err,"Signer %d:\n",iVar13);
                if (iVar7 == 0) {
                  BIO_puts(bio_err,"  No Receipt Request\n");
                }
                else if (iVar7 < 0) {
                  BIO_puts(bio_err,"  Receipt Request Parse Error\n");
                  ERR_print_errors(bio_err);
                }
                else {
                  CMS_ReceiptRequest_get0_values(local_34,&local_24,&local_30,&local_28,local_2c);
                  BIO_puts(pBVar12,"  Signed Content ID:\n");
                  iVar7 = ASN1_STRING_length(local_24);
                  bytes = ASN1_STRING_data(local_24);
                  BIO_dump_indent(pBVar12,(char *)bytes,iVar7,4);
                  iVar7 = BIO_puts(pBVar12,"  Receipts From");
                  if (local_28 == 0) {
                    if (local_30 == 1) {
                      iVar7 = BIO_puts(pBVar12,": First Tier\n");
                    }
                    else if (local_30 == 0) {
                      iVar7 = BIO_puts(pBVar12,": All\n");
                    }
                    else {
                      iVar7 = BIO_printf(pBVar12," Unknown (%d)\n",local_30,extraout_EDX_17);
                    }
                  }
                  else {
                    pcVar30 = " List:\n";
                    pBVar29 = pBVar12;
                    iVar18 = iVar7;
                    BIO_puts(pBVar12," List:\n");
                    iVar7 = gnames_stack_print(pBVar29,pcVar30,iVar7,iVar18);
                  }
                  pcVar30 = "  Receipts To:\n";
                  pBVar29 = pBVar12;
                  iVar18 = iVar7;
                  BIO_puts(pBVar12,"  Receipts To:\n");
                  gnames_stack_print(pBVar29,pcVar30,iVar7,iVar18);
                }
                iVar7 = iVar13;
                if (local_34 != (CMS_ReceiptRequest *)0x0) {
                  CMS_ReceiptRequest_free(local_34);
                }
              }
            }
            goto LAB_0808a43e;
          }
          pass = (EVP_PKEY *)0x0;
          BIO_printf(bio_err,"Verification failure\n",iVar7,iVar7);
          if (bVar6) {
            iVar7 = verify_err + 0x20;
            if (iVar7 == 0) goto LAB_0808947c;
            goto LAB_0808946b;
          }
        }
        pass = (EVP_PKEY *)0x0;
        iVar7 = 4;
      }
      goto LAB_0808946b;
    }
    if (local_104 == 0x1a) {
      a = (CMS_ReceiptRequest *)0x0;
      cms = (EVP_PKEY *)CMS_digest_create(local_e8,local_78,uVar22);
      uVar19 = extraout_ECX_07;
      uVar20 = extraout_EDX_07;
      goto LAB_0808a3c6;
    }
    if (local_104 == 0x1c) {
      a = (CMS_ReceiptRequest *)0x0;
      cms = (EVP_PKEY *)CMS_compress(local_e8,-1,uVar22);
      uVar19 = extraout_ECX_06;
      uVar20 = extraout_EDX_06;
      goto LAB_0808a3c6;
    }
    if (local_104 != 0x11) {
      if (local_104 == 0x1e) {
        a = (CMS_ReceiptRequest *)0x0;
        cms = (EVP_PKEY *)
              CMS_EncryptedData_encrypt(local_e8,local_ac,local_e4,(size_t)local_90,uVar22);
        uVar19 = extraout_ECX_12;
        uVar20 = extraout_EDX_13;
      }
      else {
        if (local_104 == 0x3f) {
          p_Var11 = (_STACK *)CMS_get0_SignerInfos((CMS_ContentInfo *)cms);
          if (p_Var11 != (_STACK *)0x0) {
            pCVar10 = (CMS_SignerInfo *)sk_value(p_Var11,0);
            pass = (EVP_PKEY *)
                   CMS_sign_receipt(pCVar10,local_d0,local_d8,(stack_st_X509 *)local_c8,uVar22);
            if (pass != (EVP_PKEY *)0x0) {
              CMS_ContentInfo_free((CMS_ContentInfo *)cms);
              uVar19 = extraout_ECX_13;
              uVar20 = extraout_EDX_14;
              cms = pass;
              goto LAB_0808a8ad;
            }
          }
LAB_0808a9a0:
          pass = (EVP_PKEY *)0x0;
          a = (CMS_ReceiptRequest *)0x0;
          iVar7 = 3;
          goto LAB_0808946b;
        }
        if (pass == (EVP_PKEY *)0x0) {
          a = (CMS_ReceiptRequest *)0x0;
        }
        else {
          if (local_104 == 0x53) {
            if (((uVar22 & 0x40) != 0) && (local_b4 = uVar22 | 0x1000, local_a4 != 6)) {
              local_b4 = uVar22;
            }
            local_b4 = local_b4 | 0x4000;
            cms = (EVP_PKEY *)
                  CMS_sign((X509 *)0x0,(EVP_PKEY *)0x0,(stack_st_X509 *)local_c8,local_e8,local_b4);
            if (cms == (EVP_PKEY *)0x0) goto LAB_0808a9a0;
            if (local_c0 != (X509_VERIFY_PARAM *)0x0) {
              pcVar31 = (code *)local_c0;
              local_9c = extraout_EDX_12;
              CMS_set1_eContentType((CMS_ContentInfo *)cms,(ASN1_OBJECT *)local_c0);
            }
            if (local_100 != (_STACK *)0x0) {
              iVar7 = make_names_stack();
              if (iVar7 != 0) {
                if (local_f4 == (_STACK *)0x0) {
                  iVar13 = 0;
                }
                else {
                  iVar13 = make_names_stack();
                  if (iVar13 == 0) goto LAB_0808a98b;
                }
                a = (CMS_ReceiptRequest *)
                    CMS_ReceiptRequest_create0(0,0xffffffff,local_b0,iVar13,iVar7,pcVar31,local_9c);
                if (a != (CMS_ReceiptRequest *)0x0) goto LAB_0808a112;
              }
LAB_0808a98b:
              BIO_puts(bio_err,"Signed Receipt Request Creation Error\n");
              goto LAB_0808a9a0;
            }
            a = (CMS_ReceiptRequest *)0x0;
          }
          else {
            local_b4 = uVar22 | 0x8000;
            a = (CMS_ReceiptRequest *)0x0;
          }
LAB_0808a112:
          for (iVar7 = 0; iVar13 = sk_num(local_fc), iVar7 < iVar13; iVar7 = iVar7 + 1) {
            local_b8 = (byte *)sk_value(local_fc,iVar7);
            pvVar16 = sk_value(local_f8,iVar7);
            local_d0 = (X509 *)load_cert(bio_err,local_b8,3,0,uVar9,"signer certificate");
            pEVar17 = local_d8;
            if ((((local_d0 == (X509 *)0x0) ||
                 (pEVar17 = (EVP_PKEY *)
                            load_key(bio_err,pvVar16,local_94,0,local_3c,uVar9,"signing key file"),
                 pEVar17 == (EVP_PKEY *)0x0)) ||
                (pCVar10 = CMS_add1_signer((CMS_ContentInfo *)cms,local_d0,pEVar17,local_78,local_b4
                                          ), pCVar10 == (CMS_SignerInfo *)0x0)) ||
               ((a != (CMS_ReceiptRequest *)0x0 &&
                (iVar13 = CMS_add1_ReceiptRequest(pCVar10,a), iVar13 == 0)))) {
              iVar7 = 3;
              pass = (EVP_PKEY *)0x0;
              local_d8 = pEVar17;
              goto LAB_0808946b;
            }
            X509_free(local_d0);
            local_d8 = (EVP_PKEY *)0x0;
            EVP_PKEY_free(pEVar17);
            local_d0 = (X509 *)0x0;
          }
          uVar19 = extraout_ECX_00;
          uVar20 = extraout_EDX_00;
          pass = local_d8;
          if (((local_104 == 0x53) && ((local_b4 & 0x1000) == 0)) &&
             (iVar7 = CMS_final((CMS_ContentInfo *)cms,local_e8,(BIO *)0x0,local_b4),
             uVar19 = extraout_ECX_01, uVar20 = extraout_EDX_01, iVar7 == 0)) {
            pass = (EVP_PKEY *)0x0;
            iVar7 = 3;
            goto LAB_0808946b;
          }
        }
      }
      goto LAB_0808a3c6;
    }
    local_b4 = uVar22 | 0x4000;
    cms = (EVP_PKEY *)CMS_encrypt((stack_st_X509 *)local_bc,local_e8,local_ac,local_b4);
    if (cms == (EVP_PKEY *)0x0) goto LAB_0808a9a0;
    uVar19 = extraout_ECX_08;
    uVar20 = extraout_EDX_08;
    if (local_e4 != (uchar *)0x0) {
      pCVar14 = CMS_add0_recipient_key
                          ((CMS_ContentInfo *)cms,0,local_e4,(size_t)local_90,local_cc,
                           (size_t)local_74,(ASN1_GENERALIZEDTIME *)0x0,(ASN1_OBJECT *)0x0,
                           (ASN1_TYPE *)0x0);
      if (pCVar14 == (CMS_RecipientInfo *)0x0) goto LAB_0808a9a0;
      local_cc = (uchar *)0x0;
      uVar19 = extraout_ECX_09;
      uVar20 = extraout_EDX_09;
    }
    if ((local_98 == (byte *)0x0) ||
       ((pass = (EVP_PKEY *)BUF_strdup((char *)local_98), pass != (EVP_PKEY *)0x0 &&
        (pCVar14 = CMS_add0_recipient_password
                             ((CMS_ContentInfo *)cms,-1,0,0,(uchar *)pass,-1,(EVP_CIPHER *)0x0),
        uVar19 = extraout_ECX_10, uVar20 = extraout_EDX_10, pCVar14 != (CMS_RecipientInfo *)0x0))))
    {
      if ((uVar22 & 0x1000) == 0) {
        pass = (EVP_PKEY *)0x0;
        iVar7 = CMS_final((CMS_ContentInfo *)cms,local_e8,(BIO *)0x0,local_b4);
        uVar19 = extraout_ECX_11;
        uVar20 = extraout_EDX_11;
        if (iVar7 == 0) goto LAB_0808a8ce;
      }
      local_e4 = (uchar *)0x0;
LAB_0808a8ad:
      a = (CMS_ReceiptRequest *)0x0;
LAB_0808a41e:
      if (bVar3) {
        if (bVar4) {
          CMS_ContentInfo_print_ctx(local_ec,(CMS_ContentInfo *)cms,0,(ASN1_PCTX *)0x0);
        }
      }
      else {
        if (local_a4 == 6) {
          if (local_68 != (byte *)0x0) {
            BIO_printf(local_ec,"To: %s\n",local_68,uVar19);
            uVar20 = extraout_EDX_15;
          }
          if (local_64 != (byte *)0x0) {
            BIO_printf(local_ec,"From: %s\n",local_64,uVar20);
          }
          if (local_60 != (byte *)0x0) {
            BIO_printf(local_ec,"Subject: %s\n",local_60,0);
          }
          if (local_104 == 0x76) {
            iVar7 = SMIME_write_CMS(local_ec,(CMS_ContentInfo *)cms,local_44,local_b4);
          }
          else {
            iVar7 = SMIME_write_CMS(local_ec,(CMS_ContentInfo *)cms,local_e8,local_b4);
          }
        }
        else if (local_a4 == 3) {
          iVar7 = PEM_write_bio_CMS_stream(local_ec,(CMS_ContentInfo *)cms,local_e8,local_b4);
        }
        else {
          if (local_a4 != 1) {
            pcVar30 = "Bad output format for CMS file\n";
            pEVar17 = pass;
            goto LAB_0808a65c;
          }
          iVar7 = i2d_CMS_bio_stream(local_ec,(CMS_ContentInfo *)cms,local_e8,local_b4);
        }
        pass = (EVP_PKEY *)0x0;
        if (iVar7 < 1) {
          iVar7 = 6;
          goto LAB_0808946b;
        }
      }
LAB_0808a43e:
      pass = (EVP_PKEY *)0x0;
      iVar7 = 0;
      goto LAB_0808947c;
    }
LAB_0808a8ce:
    local_e4 = (uchar *)0x0;
    a = (CMS_ReceiptRequest *)0x0;
    iVar7 = 3;
  }
LAB_0808946b:
  ERR_print_errors(bio_err);
LAB_0808947c:
  if (bVar2) {
    app_RAND_write_file(0,bio_err);
  }
  sk_pop_free(local_bc,X509_free);
  sk_pop_free(local_c8,X509_free);
  if (local_38 != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(local_38);
  }
  if (local_fc != (_STACK *)0x0) {
    sk_free(local_fc);
  }
  if (local_f8 != (_STACK *)0x0) {
    sk_free(local_f8);
  }
  if (local_e4 != (uchar *)0x0) {
    CRYPTO_free(local_e4);
  }
  if (local_cc != (uchar *)0x0) {
    CRYPTO_free(local_cc);
  }
  if (pass != (EVP_PKEY *)0x0) {
    CRYPTO_free(pass);
  }
  if (local_c0 != (X509_VERIFY_PARAM *)0x0) {
    ASN1_OBJECT_free((ASN1_OBJECT *)local_c0);
  }
  if (a != (CMS_ReceiptRequest *)0x0) {
    CMS_ReceiptRequest_free(a);
  }
  if (local_100 != (_STACK *)0x0) {
    sk_free(local_100);
  }
  if (local_f4 != (_STACK *)0x0) {
    sk_free(local_f4);
  }
  X509_STORE_free(local_dc);
  X509_free((X509 *)0x0);
  X509_free(local_c4);
  X509_free(local_d0);
  EVP_PKEY_free(local_d8);
  CMS_ContentInfo_free((CMS_ContentInfo *)cms);
  CMS_ContentInfo_free(local_e0);
  BIO_free(local_d4);
  BIO_free(local_e8);
  BIO_free(local_44);
  BIO_free_all(local_ec);
  if (local_3c != (void *)0x0) {
    CRYPTO_free(local_3c);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}

