
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 ocsp_main(undefined4 param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  OCSP_REQUEST *req;
  int iVar5;
  long lVar6;
  OPENSSL_STRING *ppcVar7;
  OCSP_ONEREQ *pOVar8;
  OCSP_CERTID *cid;
  int iVar9;
  char *pcVar10;
  EVP_MD *dgst;
  OCSP_SINGLERESP *x;
  BIO_METHOD *type;
  X509_NAME *issuerName;
  ASN1_BIT_STRING *issuerKey;
  ASN1_INTEGER *serialNumber;
  X509 *pXVar11;
  int iVar12;
  uint uVar13;
  BIO *pBVar14;
  OCSP_RESPONSE *a;
  char *pcVar15;
  char *pcVar16;
  undefined4 uVar17;
  undefined4 *puVar18;
  char *pcVar19;
  _STACK *st;
  OCSP_CERTID *pOVar20;
  undefined4 *puVar21;
  char *pcVar22;
  int in_GS_OFFSET;
  bool bVar23;
  bool bVar24;
  byte bVar25;
  X509 *local_180;
  X509_STORE *local_17c;
  int local_178;
  int local_174;
  long local_170;
  X509 *local_16c;
  EVP_MD *local_168;
  OCSP_BASICRESP *local_164;
  ASN1_TIME *local_160;
  BIO *local_15c;
  ASN1_TIME *local_158;
  BIO *local_154;
  EVP_PKEY *local_150;
  X509 *local_14c;
  EVP_PKEY *local_148;
  X509 *local_144;
  _STACK *local_140;
  X509 *local_13c;
  _STACK *local_138;
  int local_134;
  int local_12c;
  long local_128;
  int local_124;
  char *local_120;
  int local_11c;
  char *local_118;
  int local_110;
  ulong local_10c;
  long local_108;
  uint local_fc;
  uint local_f8;
  char *local_f4;
  int local_f0;
  long local_e8;
  long local_e4;
  stack_st_X509 *local_d8;
  char *local_c0;
  char *local_bc;
  char *local_b8;
  int local_b4;
  _STACK *local_b0;
  OCSP_REQUEST *local_ac;
  BIO *local_a8;
  ASN1_INTEGER *local_a4;
  ASN1_OBJECT *local_a0;
  ASN1_OBJECT *local_9c;
  ASN1_TIME *local_98;
  ASN1_GENERALIZEDTIME *local_94;
  ASN1_GENERALIZEDTIME *local_90;
  OPENSSL_STRING local_8c;
  undefined4 local_88;
  undefined4 local_84;
  char *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined local_71 [77];
  undefined4 local_24;
  int local_20;
  
  bVar25 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_c0 = (char *)0x0;
  local_bc = (char *)0x0;
  local_b8 = "/";
  local_b4 = -1;
  local_b0 = (_STACK *)0x0;
  local_ac = (OCSP_REQUEST *)0x0;
  local_a8 = (BIO *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar5 = load_config(bio_err,0);
  if (iVar5 == 0) {
    a = (OCSP_RESPONSE *)0x0;
    local_180 = (X509 *)0x0;
    local_140 = (_STACK *)0x0;
    local_138 = (_STACK *)0x0;
    uVar17 = 1;
    st = (_STACK *)0x0;
    local_168 = (EVP_MD *)0x0;
    local_17c = (X509_STORE *)0x0;
    local_154 = (BIO *)0x0;
    local_15c = (BIO *)0x0;
    pBVar14 = (BIO *)0x0;
    local_148 = (EVP_PKEY *)0x0;
    local_150 = (EVP_PKEY *)0x0;
    local_14c = (X509 *)0x0;
    local_16c = (X509 *)0x0;
    local_13c = (X509 *)0x0;
    local_144 = (X509 *)0x0;
    goto LAB_0808ddcb;
  }
  SSL_load_error_strings();
  SSL_library_init();
  local_138 = sk_new_null();
  local_140 = sk_new_null();
  pcVar10 = *(char **)(param_2 + 4);
  if ((pcVar10 != (char *)0x0) && (*pcVar10 == '-')) {
    local_168 = (EVP_MD *)0x0;
    local_108 = -1;
    bVar23 = true;
    local_170 = 0;
    local_174 = 0;
    local_12c = 0;
    bVar3 = false;
    local_128 = -1;
    local_fc = 0;
    local_f8 = 0;
    local_10c = 0;
    local_178 = 0;
    local_f0 = 0;
    local_110 = 0;
    local_e4 = -1;
    local_e8 = 300;
    bVar2 = false;
    bVar1 = false;
    local_13c = (X509 *)0x0;
    local_144 = (X509 *)0x0;
    bVar4 = false;
    local_11c = 1;
    local_17c = (X509_STORE *)0x0;
    local_180 = (X509 *)0x0;
    local_134 = 0;
    local_124 = 0;
    local_118 = (char *)0x0;
    local_120 = (char *)0x0;
    local_f4 = (char *)0x0;
    local_16c = (X509 *)0x0;
    pcVar15 = (char *)0x0;
    do {
      iVar5 = param_2 + 4;
      iVar12 = 5;
      pcVar16 = pcVar10;
      pcVar19 = "-out";
      do {
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        bVar23 = *pcVar16 == *pcVar19;
        pcVar16 = pcVar16 + (uint)bVar25 * -2 + 1;
        pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
      } while (bVar23);
      pcVar16 = pcVar15;
      if (bVar23) {
        pcVar16 = *(char **)(param_2 + 8);
        if (pcVar16 == (char *)0x0) goto LAB_0808e1d2;
        iVar5 = param_2 + 8;
        bVar24 = false;
      }
      else {
        iVar12 = 9;
        pcVar19 = pcVar10;
        pcVar22 = "-timeout";
        do {
          if (iVar12 == 0) break;
          iVar12 = iVar12 + -1;
          bVar23 = *pcVar19 == *pcVar22;
          pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
          pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
        } while (bVar23);
        if (bVar23) {
          if (*(char **)(param_2 + 8) == (char *)0x0) goto LAB_0808e1d2;
          iVar5 = param_2 + 8;
          lVar6 = strtol(*(char **)(param_2 + 8),(char **)0x0,10);
          bVar24 = false;
          if (lVar6 < 0) {
            BIO_printf(bio_err,"Illegal timeout value %s\n",*(undefined4 *)(param_2 + 8));
            bVar24 = true;
          }
        }
        else {
          iVar12 = 5;
          pcVar19 = pcVar10;
          pcVar22 = "-url";
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            bVar23 = *pcVar19 == *pcVar22;
            pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
            pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
          } while (bVar23);
          if (bVar23) {
            if (*(char **)(param_2 + 8) == (char *)0x0) goto LAB_0808e1d2;
            iVar5 = param_2 + 8;
            iVar12 = OCSP_parse_url(*(char **)(param_2 + 8),&local_c0,&local_bc,&local_b8,&local_b4)
            ;
            bVar24 = false;
            if (iVar12 == 0) {
              BIO_printf(bio_err,"Error parsing URL\n");
              bVar24 = true;
            }
          }
          else {
            iVar12 = 6;
            pcVar19 = pcVar10;
            pcVar22 = "-host";
            do {
              if (iVar12 == 0) break;
              iVar12 = iVar12 + -1;
              bVar23 = *pcVar19 == *pcVar22;
              pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
              pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
            } while (bVar23);
            if (bVar23) {
              if (*(char **)(param_2 + 8) == (char *)0x0) goto LAB_0808e1d2;
              iVar5 = param_2 + 8;
              bVar24 = false;
              local_c0 = *(char **)(param_2 + 8);
            }
            else {
              iVar12 = 6;
              pcVar19 = pcVar10;
              pcVar22 = "-port";
              do {
                if (iVar12 == 0) break;
                iVar12 = iVar12 + -1;
                bVar23 = *pcVar19 == *pcVar22;
                pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
              } while (bVar23);
              if (bVar23) {
                if (*(char **)(param_2 + 8) == (char *)0x0) goto LAB_0808e1d2;
                iVar5 = param_2 + 8;
                bVar24 = false;
                local_bc = *(char **)(param_2 + 8);
              }
              else {
                iVar12 = 8;
                pcVar19 = pcVar10;
                pcVar22 = "-header";
                do {
                  if (iVar12 == 0) break;
                  iVar12 = iVar12 + -1;
                  bVar23 = *pcVar19 == *pcVar22;
                  pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                  pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                } while (bVar23);
                if (bVar23) {
                  if ((*(char **)(param_2 + 8) == (char *)0x0) ||
                     (*(char **)(param_2 + 0xc) == (char *)0x0)) goto LAB_0808e1d2;
                  iVar5 = X509V3_add_value(*(char **)(param_2 + 8),*(char **)(param_2 + 0xc),
                                           (stack_st_CONF_VALUE **)&local_b0);
                  if (iVar5 == 0) goto LAB_0808effc;
                  iVar5 = param_2 + 0xc;
                  bVar24 = false;
                }
                else {
                  iVar12 = 0xc;
                  pcVar19 = pcVar10;
                  pcVar22 = "-ignore_err";
                  do {
                    if (iVar12 == 0) break;
                    iVar12 = iVar12 + -1;
                    bVar23 = *pcVar19 == *pcVar22;
                    pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                    pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                  } while (bVar23);
                  if (bVar23) {
                    bVar3 = true;
                    bVar24 = false;
                  }
                  else {
                    iVar12 = 10;
                    pcVar19 = pcVar10;
                    pcVar22 = "-noverify";
                    do {
                      if (iVar12 == 0) break;
                      iVar12 = iVar12 + -1;
                      bVar23 = *pcVar19 == *pcVar22;
                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                    } while (bVar23);
                    if (bVar23) {
                      bVar24 = false;
                      bVar4 = true;
                    }
                    else {
                      iVar12 = 7;
                      pcVar19 = pcVar10;
                      pcVar22 = "-nonce";
                      do {
                        if (iVar12 == 0) break;
                        iVar12 = iVar12 + -1;
                        bVar23 = *pcVar19 == *pcVar22;
                        pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                        pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                      } while (bVar23);
                      if (bVar23) {
                        bVar24 = false;
                        local_11c = 2;
                      }
                      else {
                        iVar12 = 10;
                        pcVar19 = pcVar10;
                        pcVar22 = "-no_nonce";
                        do {
                          if (iVar12 == 0) break;
                          iVar12 = iVar12 + -1;
                          bVar23 = *pcVar19 == *pcVar22;
                          pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                          pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                        } while (bVar23);
                        if (bVar23) {
                          bVar24 = false;
                          local_11c = 0;
                        }
                        else {
                          iVar12 = 0xf;
                          pcVar19 = pcVar10;
                          pcVar22 = "-resp_no_certs";
                          do {
                            if (iVar12 == 0) break;
                            iVar12 = iVar12 + -1;
                            bVar23 = *pcVar19 == *pcVar22;
                            pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                            pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                          } while (bVar23);
                          if (bVar23) {
                            local_fc = local_fc | 1;
                            bVar24 = false;
                          }
                          else {
                            iVar12 = 0xd;
                            pcVar19 = pcVar10;
                            pcVar22 = "-resp_key_id";
                            do {
                              if (iVar12 == 0) break;
                              iVar12 = iVar12 + -1;
                              bVar23 = *pcVar19 == *pcVar22;
                              pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                              pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                            } while (bVar23);
                            if (bVar23) {
                              local_fc = local_fc | 0x400;
                              bVar24 = false;
                            }
                            else {
                              iVar12 = 10;
                              pcVar19 = pcVar10;
                              pcVar22 = "-no_certs";
                              do {
                                if (iVar12 == 0) break;
                                iVar12 = iVar12 + -1;
                                bVar23 = *pcVar19 == *pcVar22;
                                pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                              } while (bVar23);
                              if (bVar23) {
                                bVar24 = false;
                                local_10c = 1;
                              }
                              else {
                                iVar12 = 0x15;
                                pcVar19 = pcVar10;
                                pcVar22 = "-no_signature_verify";
                                do {
                                  if (iVar12 == 0) break;
                                  iVar12 = iVar12 + -1;
                                  bVar23 = *pcVar19 == *pcVar22;
                                  pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                  pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                } while (bVar23);
                                if (bVar23) {
                                  local_f8 = local_f8 | 4;
                                  bVar24 = false;
                                }
                                else {
                                  iVar12 = 0x10;
                                  pcVar19 = pcVar10;
                                  pcVar22 = "-no_cert_verify";
                                  do {
                                    if (iVar12 == 0) break;
                                    iVar12 = iVar12 + -1;
                                    bVar23 = *pcVar19 == *pcVar22;
                                    pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                    pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                  } while (bVar23);
                                  if (bVar23) {
                                    local_f8 = local_f8 | 0x10;
                                    bVar24 = false;
                                  }
                                  else {
                                    iVar12 = 10;
                                    pcVar19 = pcVar10;
                                    pcVar22 = "-no_chain";
                                    do {
                                      if (iVar12 == 0) break;
                                      iVar12 = iVar12 + -1;
                                      bVar23 = *pcVar19 == *pcVar22;
                                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                    } while (bVar23);
                                    if (bVar23) {
                                      local_f8 = local_f8 | 8;
                                      bVar24 = false;
                                    }
                                    else {
                                      iVar12 = 0x10;
                                      pcVar19 = pcVar10;
                                      pcVar22 = "-no_cert_checks";
                                      do {
                                        if (iVar12 == 0) break;
                                        iVar12 = iVar12 + -1;
                                        bVar23 = *pcVar19 == *pcVar22;
                                        pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                        pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                      } while (bVar23);
                                      if (bVar23) {
                                        local_f8 = local_f8 | 0x100;
                                        bVar24 = false;
                                      }
                                      else {
                                        iVar12 = 0xd;
                                        pcVar19 = pcVar10;
                                        pcVar22 = "-no_explicit";
                                        do {
                                          if (iVar12 == 0) break;
                                          iVar12 = iVar12 + -1;
                                          bVar23 = *pcVar19 == *pcVar22;
                                          pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                          pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                        } while (bVar23);
                                        if (bVar23) {
                                          local_f8 = local_f8 | 0x20;
                                          bVar24 = false;
                                        }
                                        else {
                                          iVar12 = 0xd;
                                          pcVar19 = pcVar10;
                                          pcVar22 = "-trust_other";
                                          do {
                                            if (iVar12 == 0) break;
                                            iVar12 = iVar12 + -1;
                                            bVar23 = *pcVar19 == *pcVar22;
                                            pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                            pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                          } while (bVar23);
                                          if (bVar23) {
                                            local_f8 = local_f8 | 0x200;
                                            bVar24 = false;
                                          }
                                          else {
                                            iVar12 = 0xb;
                                            pcVar19 = pcVar10;
                                            pcVar22 = "-no_intern";
                                            do {
                                              if (iVar12 == 0) break;
                                              iVar12 = iVar12 + -1;
                                              bVar23 = *pcVar19 == *pcVar22;
                                              pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                              pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                            } while (bVar23);
                                            if (bVar23) {
                                              local_f8 = local_f8 | 2;
                                              bVar24 = false;
                                            }
                                            else {
                                              iVar12 = 6;
                                              pcVar19 = pcVar10;
                                              pcVar22 = "-text";
                                              do {
                                                if (iVar12 == 0) break;
                                                iVar12 = iVar12 + -1;
                                                bVar23 = *pcVar19 == *pcVar22;
                                                pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                              } while (bVar23);
                                              if (bVar23) {
                                                bVar24 = false;
                                                bVar2 = true;
                                                bVar1 = true;
                                              }
                                              else {
                                                iVar12 = 10;
                                                pcVar19 = pcVar10;
                                                pcVar22 = "-req_text";
                                                do {
                                                  if (iVar12 == 0) break;
                                                  iVar12 = iVar12 + -1;
                                                  bVar23 = *pcVar19 == *pcVar22;
                                                  pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                  pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                } while (bVar23);
                                                if (bVar23) {
                                                  bVar24 = false;
                                                  bVar1 = true;
                                                }
                                                else {
                                                  iVar12 = 0xb;
                                                  pcVar19 = pcVar10;
                                                  pcVar22 = "-resp_text";
                                                  do {
                                                    if (iVar12 == 0) break;
                                                    iVar12 = iVar12 + -1;
                                                    bVar23 = *pcVar19 == *pcVar22;
                                                    pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                    pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                  } while (bVar23);
                                                  if (bVar23) {
                                                    bVar24 = false;
                                                    bVar2 = true;
                                                  }
                                                  else {
                                                    iVar12 = 7;
                                                    pcVar19 = pcVar10;
                                                    pcVar22 = "-reqin";
                                                    do {
                                                      if (iVar12 == 0) break;
                                                      iVar12 = iVar12 + -1;
                                                      bVar23 = *pcVar19 == *pcVar22;
                                                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                    } while (bVar23);
                                                    if (bVar23) {
                                                      if (*(char **)(param_2 + 8) != (char *)0x0) {
                                                        iVar5 = param_2 + 8;
                                                        bVar24 = false;
                                                        local_16c = (X509 *)*(char **)(param_2 + 8);
                                                        goto LAB_0808e082;
                                                      }
                                                    }
                                                    else {
                                                      iVar12 = 8;
                                                      pcVar19 = pcVar10;
                                                      pcVar22 = "-respin";
                                                      do {
                                                        if (iVar12 == 0) break;
                                                        iVar12 = iVar12 + -1;
                                                        bVar23 = *pcVar19 == *pcVar22;
                                                        pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                        pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                      } while (bVar23);
                                                      if (bVar23) {
                                                        if (*(char **)(param_2 + 8) != (char *)0x0)
                                                        {
                                                          iVar5 = param_2 + 8;
                                                          bVar24 = false;
                                                          local_f4 = *(char **)(param_2 + 8);
                                                          goto LAB_0808e082;
                                                        }
                                                      }
                                                      else {
                                                        iVar12 = 8;
                                                        pcVar19 = pcVar10;
                                                        pcVar22 = "-signer";
                                                        do {
                                                          if (iVar12 == 0) break;
                                                          iVar12 = iVar12 + -1;
                                                          bVar23 = *pcVar19 == *pcVar22;
                                                          pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                          pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                        } while (bVar23);
                                                        if (bVar23) {
                                                          if (*(int *)(param_2 + 8) != 0) {
                                                            iVar5 = param_2 + 8;
                                                            bVar24 = false;
                                                            local_124 = *(int *)(param_2 + 8);
                                                            goto LAB_0808e082;
                                                          }
                                                        }
                                                        else {
                                                          iVar12 = 8;
                                                          pcVar19 = pcVar10;
                                                          pcVar22 = "-VAfile";
                                                          do {
                                                            if (iVar12 == 0) break;
                                                            iVar12 = iVar12 + -1;
                                                            bVar23 = *pcVar19 == *pcVar22;
                                                            pcVar19 = pcVar19 + (uint)bVar25 * -2 +
                                                                                1;
                                                            pcVar22 = pcVar22 + (uint)bVar25 * -2 +
                                                                                1;
                                                          } while (bVar23);
                                                          if (bVar23) {
                                                            if (*(int *)(param_2 + 8) != 0) {
                                                              iVar5 = param_2 + 8;
                                                              local_f8 = local_f8 | 0x200;
                                                              bVar24 = false;
                                                              local_f0 = *(int *)(param_2 + 8);
                                                              goto LAB_0808e082;
                                                            }
                                                          }
                                                          else {
                                                            iVar12 = 0xc;
                                                            pcVar19 = pcVar10;
                                                            pcVar22 = "-sign_other";
                                                            do {
                                                              if (iVar12 == 0) break;
                                                              iVar12 = iVar12 + -1;
                                                              bVar23 = *pcVar19 == *pcVar22;
                                                              pcVar19 = pcVar19 + (uint)bVar25 * -2
                                                                                  + 1;
                                                              pcVar22 = pcVar22 + (uint)bVar25 * -2
                                                                                  + 1;
                                                            } while (bVar23);
                                                            if (bVar23) {
                                                              if (*(int *)(param_2 + 8) != 0) {
                                                                iVar5 = param_2 + 8;
                                                                bVar24 = false;
                                                                local_110 = *(int *)(param_2 + 8);
                                                                goto LAB_0808e082;
                                                              }
                                                            }
                                                            else {
                                                              iVar12 = 0xe;
                                                              pcVar19 = pcVar10;
                                                              pcVar22 = "-verify_other";
                                                              do {
                                                                if (iVar12 == 0) break;
                                                                iVar12 = iVar12 + -1;
                                                                bVar23 = *pcVar19 == *pcVar22;
                                                                pcVar19 = pcVar19 + (uint)bVar25 *
                                                                                    -2 + 1;
                                                                pcVar22 = pcVar22 + (uint)bVar25 *
                                                                                    -2 + 1;
                                                              } while (bVar23);
                                                              if (bVar23) {
                                                                if (*(int *)(param_2 + 8) != 0) {
                                                                  iVar5 = param_2 + 8;
                                                                  bVar24 = false;
                                                                  local_f0 = *(int *)(param_2 + 8);
                                                                  goto LAB_0808e082;
                                                                }
                                                              }
                                                              else {
                                                                iVar12 = 8;
                                                                pcVar19 = pcVar10;
                                                                pcVar22 = "-CAfile";
                                                                do {
                                                                  if (iVar12 == 0) break;
                                                                  iVar12 = iVar12 + -1;
                                                                  bVar23 = *pcVar19 == *pcVar22;
                                                                  pcVar19 = pcVar19 + (uint)bVar25 *
                                                                                      -2 + 1;
                                                                  pcVar22 = pcVar22 + (uint)bVar25 *
                                                                                      -2 + 1;
                                                                } while (bVar23);
                                                                if (bVar23) {
                                                                  if (*(int *)(param_2 + 8) != 0) {
                                                                    iVar5 = param_2 + 8;
                                                                    bVar24 = false;
                                                                    goto LAB_0808e082;
                                                                  }
                                                                }
                                                                else {
                                                                  iVar12 = 8;
                                                                  pcVar19 = pcVar10;
                                                                  pcVar22 = "-CApath";
                                                                  do {
                                                                    if (iVar12 == 0) break;
                                                                    iVar12 = iVar12 + -1;
                                                                    bVar23 = *pcVar19 == *pcVar22;
                                                                    pcVar19 = pcVar19 + (uint)bVar25
                                                                                        * -2 + 1;
                                                                    pcVar22 = pcVar22 + (uint)bVar25
                                                                                        * -2 + 1;
                                                                  } while (bVar23);
                                                                  if (bVar23) {
                                                                    if (*(int *)(param_2 + 8) != 0)
                                                                    {
                                                                      iVar5 = param_2 + 8;
                                                                      bVar24 = false;
                                                                      goto LAB_0808e082;
                                                                    }
                                                                  }
                                                                  else {
                                                                    iVar12 = 0x11;
                                                                    pcVar19 = pcVar10;
                                                                    pcVar22 = "-validity_period";
                                                                    do {
                                                                      if (iVar12 == 0) break;
                                                                      iVar12 = iVar12 + -1;
                                                                      bVar23 = *pcVar19 == *pcVar22;
                                                                      pcVar19 = pcVar19 + (uint)
                                                  bVar25 * -2 + 1;
                                                  pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                  } while (bVar23);
                                                  if (bVar23) {
                                                    if (*(char **)(param_2 + 8) != (char *)0x0) {
                                                      iVar5 = param_2 + 8;
                                                      local_e8 = strtol(*(char **)(param_2 + 8),
                                                                        (char **)0x0,10);
                                                      bVar24 = false;
                                                      if (local_e8 < 0) {
                                                        BIO_printf(bio_err,
                                                  "Illegal validity period %s\n",
                                                  *(undefined4 *)(param_2 + 8));
                                                  bVar24 = true;
                                                  }
                                                  goto LAB_0808e082;
                                                  }
                                                  }
                                                  else {
                                                    iVar12 = 0xc;
                                                    pcVar19 = pcVar10;
                                                    pcVar22 = "-status_age";
                                                    do {
                                                      if (iVar12 == 0) break;
                                                      iVar12 = iVar12 + -1;
                                                      bVar23 = *pcVar19 == *pcVar22;
                                                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                    } while (bVar23);
                                                    if (bVar23) {
                                                      if (*(char **)(param_2 + 8) != (char *)0x0) {
                                                        iVar5 = param_2 + 8;
                                                        local_e4 = strtol(*(char **)(param_2 + 8),
                                                                          (char **)0x0,10);
                                                        bVar24 = false;
                                                        if (local_e4 < 0) {
                                                          BIO_printf(bio_err,
                                                  "Illegal validity age %s\n",
                                                  *(undefined4 *)(param_2 + 8));
                                                  bVar24 = true;
                                                  }
                                                  goto LAB_0808e082;
                                                  }
                                                  }
                                                  else {
                                                    iVar12 = 9;
                                                    pcVar19 = pcVar10;
                                                    pcVar22 = "-signkey";
                                                    do {
                                                      if (iVar12 == 0) break;
                                                      iVar12 = iVar12 + -1;
                                                      bVar23 = *pcVar19 == *pcVar22;
                                                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                    } while (bVar23);
                                                    if (bVar23) {
                                                      if (*(int *)(param_2 + 8) != 0) {
                                                        iVar5 = param_2 + 8;
                                                        bVar24 = false;
                                                        local_134 = *(int *)(param_2 + 8);
                                                        goto LAB_0808e082;
                                                      }
                                                    }
                                                    else {
                                                      iVar12 = 8;
                                                      pcVar19 = pcVar10;
                                                      pcVar22 = "-reqout";
                                                      do {
                                                        if (iVar12 == 0) break;
                                                        iVar12 = iVar12 + -1;
                                                        bVar23 = *pcVar19 == *pcVar22;
                                                        pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                        pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                      } while (bVar23);
                                                      if (bVar23) {
                                                        if (*(char **)(param_2 + 8) != (char *)0x0)
                                                        {
                                                          iVar5 = param_2 + 8;
                                                          bVar24 = false;
                                                          local_120 = *(char **)(param_2 + 8);
                                                          goto LAB_0808e082;
                                                        }
                                                      }
                                                      else {
                                                        iVar12 = 9;
                                                        pcVar19 = pcVar10;
                                                        pcVar22 = "-respout";
                                                        do {
                                                          if (iVar12 == 0) break;
                                                          iVar12 = iVar12 + -1;
                                                          bVar23 = *pcVar19 == *pcVar22;
                                                          pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                          pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                        } while (bVar23);
                                                        if (bVar23) {
                                                          if (*(char **)(param_2 + 8) != (char *)0x0
                                                             ) {
                                                            iVar5 = param_2 + 8;
                                                            bVar24 = false;
                                                            local_118 = *(char **)(param_2 + 8);
                                                            goto LAB_0808e082;
                                                          }
                                                        }
                                                        else {
                                                          iVar12 = 6;
                                                          pcVar19 = pcVar10;
                                                          pcVar22 = "-path";
                                                          do {
                                                            if (iVar12 == 0) break;
                                                            iVar12 = iVar12 + -1;
                                                            bVar23 = *pcVar19 == *pcVar22;
                                                            pcVar19 = pcVar19 + (uint)bVar25 * -2 +
                                                                                1;
                                                            pcVar22 = pcVar22 + (uint)bVar25 * -2 +
                                                                                1;
                                                          } while (bVar23);
                                                          if (bVar23) {
                                                            if (*(char **)(param_2 + 8) !=
                                                                (char *)0x0) {
                                                              iVar5 = param_2 + 8;
                                                              bVar24 = false;
                                                              local_b8 = *(char **)(param_2 + 8);
                                                              goto LAB_0808e082;
                                                            }
                                                          }
                                                          else {
                                                            iVar12 = 8;
                                                            pcVar19 = pcVar10;
                                                            pcVar22 = "-issuer";
                                                            do {
                                                              if (iVar12 == 0) break;
                                                              iVar12 = iVar12 + -1;
                                                              bVar23 = *pcVar19 == *pcVar22;
                                                              pcVar19 = pcVar19 + (uint)bVar25 * -2
                                                                                  + 1;
                                                              pcVar22 = pcVar22 + (uint)bVar25 * -2
                                                                                  + 1;
                                                            } while (bVar23);
                                                            if (bVar23) {
                                                              if (*(int *)(param_2 + 8) != 0) {
                                                                X509_free(local_144);
                                                                local_144 = (X509 *)load_cert(
                                                  bio_err,*(undefined4 *)(param_2 + 8),3,0,0,
                                                  "issuer certificate");
                                                  pXVar11 = local_144;
joined_r0x0808ffdb:
                                                  iVar12 = local_178;
                                                  if (pXVar11 != (X509 *)0x0) {
LAB_0808ffe1:
                                                    local_178 = iVar12;
                                                    iVar5 = param_2 + 8;
                                                    bVar24 = false;
                                                    goto LAB_0808e082;
                                                  }
                                                  goto LAB_0808effc;
                                                  }
                                                  }
                                                  else {
                                                    iVar12 = 6;
                                                    pcVar19 = pcVar10;
                                                    pcVar22 = "-cert";
                                                    do {
                                                      if (iVar12 == 0) break;
                                                      iVar12 = iVar12 + -1;
                                                      bVar23 = *pcVar19 == *pcVar22;
                                                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                    } while (bVar23);
                                                    if (bVar23) {
                                                      if (*(int *)(param_2 + 8) != 0) {
                                                        X509_free(local_13c);
                                                        local_13c = (X509 *)load_cert(bio_err,*(
                                                  undefined4 *)(param_2 + 8),3,0,0,"certificate");
                                                  if (local_13c != (X509 *)0x0) {
                                                    if (local_168 == (EVP_MD *)0x0) {
                                                      local_168 = EVP_sha1();
                                                    }
                                                    if (local_144 == (X509 *)0x0) {
LAB_080900c6:
                                                      BIO_printf(bio_err,
                                                  "No issuer certificate specified\n");
                                                  }
                                                  else {
                                                    if ((local_ac != (OCSP_REQUEST *)0x0) ||
                                                       (local_ac = OCSP_REQUEST_new(),
                                                       local_ac != (OCSP_REQUEST *)0x0)) {
                                                      pOVar20 = OCSP_cert_to_id(local_168,local_13c,
                                                                                local_144);
joined_r0x0809018b:
                                                      if (((pOVar20 != (OCSP_CERTID *)0x0) &&
                                                          (iVar5 = sk_push(local_140,pOVar20),
                                                          iVar5 != 0)) &&
                                                         (pOVar8 = OCSP_request_add0_id
                                                                             (local_ac,pOVar20),
                                                         pOVar8 != (OCSP_ONEREQ *)0x0)) {
                                                        pXVar11 = (X509 *)sk_push(local_138,
                                                                                  *(void **)(param_2
                                                                                            + 8));
                                                        goto joined_r0x0808ffdb;
                                                      }
                                                    }
LAB_08090099:
                                                    BIO_printf(bio_err,
                                                  "Error Creating OCSP request\n");
                                                  }
                                                  }
                                                  goto LAB_0808effc;
                                                  }
                                                  }
                                                  else {
                                                    iVar12 = 8;
                                                    pcVar19 = pcVar10;
                                                    pcVar22 = "-serial";
                                                    do {
                                                      if (iVar12 == 0) break;
                                                      iVar12 = iVar12 + -1;
                                                      bVar23 = *pcVar19 == *pcVar22;
                                                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                    } while (bVar23);
                                                    if (!bVar23) {
                                                      iVar12 = 7;
                                                      pcVar19 = pcVar10;
                                                      pcVar22 = "-index";
                                                      do {
                                                        if (iVar12 == 0) break;
                                                        iVar12 = iVar12 + -1;
                                                        bVar23 = *pcVar19 == *pcVar22;
                                                        pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                        pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                      } while (bVar23);
                                                      if (bVar23) {
                                                        if (*(int *)(param_2 + 8) == 0)
                                                        goto LAB_0808e1d2;
                                                        iVar5 = param_2 + 8;
                                                        bVar24 = false;
                                                        local_12c = *(int *)(param_2 + 8);
                                                      }
                                                      else {
                                                        bVar23 = pcVar10[1] == 'C';
                                                        if (((bVar23) &&
                                                            (bVar23 = pcVar10[2] == 'A', bVar23)) &&
                                                           (bVar23 = pcVar10[3] == '\0', bVar23)) {
                                                          if (*(int *)(param_2 + 8) == 0)
                                                          goto LAB_0808e1d2;
                                                          iVar5 = param_2 + 8;
                                                          bVar24 = false;
                                                          local_174 = *(int *)(param_2 + 8);
                                                        }
                                                        else {
                                                          iVar12 = 6;
                                                          pcVar19 = pcVar10;
                                                          pcVar22 = "-nmin";
                                                          do {
                                                            if (iVar12 == 0) break;
                                                            iVar12 = iVar12 + -1;
                                                            bVar23 = *pcVar19 == *pcVar22;
                                                            pcVar19 = pcVar19 + (uint)bVar25 * -2 +
                                                                                1;
                                                            pcVar22 = pcVar22 + (uint)bVar25 * -2 +
                                                                                1;
                                                          } while (bVar23);
                                                          if (bVar23) {
                                                            if (*(char **)(param_2 + 8) ==
                                                                (char *)0x0) {
                                                              bVar24 = false;
                                                            }
                                                            else {
                                                              iVar5 = param_2 + 8;
                                                              local_170 = strtol(*(char **)(param_2 
                                                  + 8),(char **)0x0,10);
                                                  bVar24 = false;
                                                  if (local_170 < 0) {
                                                    BIO_printf(bio_err,"Illegal update period %s\n",
                                                               *(undefined4 *)(param_2 + 8));
                                                    bVar24 = true;
                                                  }
                                                  }
                                                  if (local_108 != -1) goto LAB_0808e1d2;
                                                  local_108 = 0;
                                                  }
                                                  else {
                                                    iVar12 = 10;
                                                    pcVar19 = pcVar10;
                                                    pcVar22 = "-nrequest";
                                                    do {
                                                      if (iVar12 == 0) break;
                                                      iVar12 = iVar12 + -1;
                                                      bVar23 = *pcVar19 == *pcVar22;
                                                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                    } while (bVar23);
                                                    if (bVar23) {
                                                      if (*(char **)(param_2 + 8) == (char *)0x0)
                                                      goto LAB_0808e1d2;
                                                      iVar5 = param_2 + 8;
                                                      local_128 = strtol(*(char **)(param_2 + 8),
                                                                         (char **)0x0,10);
                                                      bVar24 = false;
                                                      if (local_128 < 0) {
                                                        BIO_printf(bio_err,
                                                  "Illegal accept count %s\n",
                                                  *(undefined4 *)(param_2 + 8));
                                                  bVar24 = true;
                                                  }
                                                  }
                                                  else {
                                                    iVar12 = 7;
                                                    pcVar19 = pcVar10;
                                                    pcVar22 = "-ndays";
                                                    do {
                                                      if (iVar12 == 0) break;
                                                      iVar12 = iVar12 + -1;
                                                      bVar23 = *pcVar19 == *pcVar22;
                                                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                    } while (bVar23);
                                                    if (bVar23) {
                                                      if (*(char **)(param_2 + 8) == (char *)0x0)
                                                      goto LAB_0808e1d2;
                                                      iVar5 = param_2 + 8;
                                                      local_108 = strtol(*(char **)(param_2 + 8),
                                                                         (char **)0x0,10);
                                                      bVar24 = false;
                                                      if (local_108 < 0) {
                                                        BIO_printf(bio_err,
                                                  "Illegal update period %s\n",
                                                  *(undefined4 *)(param_2 + 8));
                                                  bVar24 = true;
                                                  }
                                                  }
                                                  else {
                                                    iVar12 = 9;
                                                    pcVar19 = pcVar10;
                                                    pcVar22 = "-rsigner";
                                                    do {
                                                      if (iVar12 == 0) break;
                                                      iVar12 = iVar12 + -1;
                                                      bVar23 = *pcVar19 == *pcVar22;
                                                      pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                      pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                    } while (bVar23);
                                                    if (bVar23) {
                                                      if (*(int *)(param_2 + 8) == 0)
                                                      goto LAB_0808e1d2;
                                                      iVar5 = param_2 + 8;
                                                      bVar24 = false;
                                                      local_180 = (X509 *)*(int *)(param_2 + 8);
                                                    }
                                                    else {
                                                      iVar12 = 6;
                                                      pcVar19 = pcVar10;
                                                      pcVar22 = "-rkey";
                                                      do {
                                                        if (iVar12 == 0) break;
                                                        iVar12 = iVar12 + -1;
                                                        bVar23 = *pcVar19 == *pcVar22;
                                                        pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                        pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                      } while (bVar23);
                                                      if (bVar23) {
                                                        if (*(int *)(param_2 + 8) == 0)
                                                        goto LAB_0808e1d2;
                                                        iVar5 = param_2 + 8;
                                                        bVar24 = false;
                                                        local_17c = (X509_STORE *)
                                                                    *(int *)(param_2 + 8);
                                                      }
                                                      else {
                                                        iVar12 = 8;
                                                        pcVar19 = pcVar10;
                                                        pcVar22 = "-rother";
                                                        do {
                                                          if (iVar12 == 0) break;
                                                          iVar12 = iVar12 + -1;
                                                          bVar23 = *pcVar19 == *pcVar22;
                                                          pcVar19 = pcVar19 + (uint)bVar25 * -2 + 1;
                                                          pcVar22 = pcVar22 + (uint)bVar25 * -2 + 1;
                                                        } while (bVar23);
                                                        if (bVar23) {
                                                          iVar12 = *(int *)(param_2 + 8);
                                                          if (*(int *)(param_2 + 8) != 0)
                                                          goto LAB_0808ffe1;
                                                          goto LAB_0808e1d2;
                                                        }
                                                        local_168 = EVP_get_digestbyname
                                                                              (pcVar10 + 1);
                                                        bVar24 = local_168 == (EVP_MD *)0x0;
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_0808e082;
                                                  }
                                                  pcVar10 = *(char **)(param_2 + 8);
                                                  if (pcVar10 != (char *)0x0) {
                                                    if (local_168 == (EVP_MD *)0x0) {
                                                      local_168 = EVP_sha1();
                                                      pcVar10 = *(char **)(param_2 + 8);
                                                    }
                                                    if (local_144 == (X509 *)0x0) goto LAB_080900c6;
                                                    if ((local_ac == (OCSP_REQUEST *)0x0) &&
                                                       (local_ac = OCSP_REQUEST_new(),
                                                       local_ac == (OCSP_REQUEST *)0x0))
                                                    goto LAB_08090099;
                                                    issuerName = X509_get_subject_name(local_144);
                                                    issuerKey = X509_get0_pubkey_bitstr(local_144);
                                                    serialNumber = s2i_ASN1_INTEGER((
                                                  X509V3_EXT_METHOD *)0x0,pcVar10);
                                                  if (serialNumber != (ASN1_INTEGER *)0x0) {
                                                    pOVar20 = OCSP_cert_id_new(local_168,issuerName,
                                                                               issuerKey,
                                                                               serialNumber);
                                                    ASN1_INTEGER_free(serialNumber);
                                                    goto joined_r0x0809018b;
                                                  }
                                                  BIO_printf(bio_err,
                                                  "Error converting serial number %s\n",pcVar10);
                                                  goto LAB_0808effc;
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
LAB_0808e1d2:
                                                  bVar24 = true;
                                                  pcVar16 = pcVar15;
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
LAB_0808e082:
      if (bVar24) {
        bVar24 = true;
        goto LAB_0808e215;
      }
      pcVar10 = *(char **)(iVar5 + 4);
      if ((pcVar10 == (char *)0x0) ||
         (bVar23 = *pcVar10 == '-', pcVar15 = pcVar16, param_2 = iVar5, !bVar23)) goto LAB_0808e215;
    } while( true );
  }
  local_108 = -1;
  local_170 = 0;
  pcVar16 = (char *)0x0;
  local_174 = 0;
  local_12c = 0;
  bVar24 = false;
  bVar3 = false;
  local_128 = -1;
  local_fc = 0;
  local_f8 = 0;
  local_10c = 0;
  local_178 = 0;
  local_f0 = 0;
  local_110 = 0;
  local_e4 = -1;
  local_e8 = 300;
  bVar2 = false;
  bVar1 = false;
  local_13c = (X509 *)0x0;
  local_144 = (X509 *)0x0;
  bVar4 = false;
  local_11c = 1;
  local_17c = (X509_STORE *)0x0;
  local_180 = (X509 *)0x0;
  local_134 = 0;
  local_124 = 0;
  local_118 = (char *)0x0;
  local_120 = (char *)0x0;
  local_f4 = (char *)0x0;
  local_16c = (X509 *)0x0;
LAB_0808e215:
  if (((((local_ac == (OCSP_REQUEST *)0x0) && (local_16c == (X509 *)0x0)) &&
       (local_f4 == (char *)0x0)) && ((local_bc == (char *)0x0 || (local_12c == 0)))) || (bVar24)) {
    BIO_printf(bio_err,"OCSP utility\n");
    BIO_printf(bio_err,"Usage ocsp [options]\n");
    BIO_printf(bio_err,"where options are\n");
    BIO_printf(bio_err,"-out file          output filename\n");
    BIO_printf(bio_err,"-issuer file       issuer certificate\n");
    BIO_printf(bio_err,"-cert file         certificate to check\n");
    BIO_printf(bio_err,"-serial n          serial number to check\n");
    BIO_printf(bio_err,"-signer file       certificate to sign OCSP request with\n");
    BIO_printf(bio_err,"-signkey file      private key to sign OCSP request with\n");
    BIO_printf(bio_err,"-sign_other file   additional certificates to include in signed request\n");
    BIO_printf(bio_err,"-no_certs          don\'t include any certificates in signed request\n");
    BIO_printf(bio_err,"-req_text          print text form of request\n");
    BIO_printf(bio_err,"-resp_text         print text form of response\n");
    BIO_printf(bio_err,"-text              print text form of request and response\n");
    BIO_printf(bio_err,"-reqout file       write DER encoded OCSP request to \"file\"\n");
    BIO_printf(bio_err,"-respout file      write DER encoded OCSP reponse to \"file\"\n");
    BIO_printf(bio_err,"-reqin file        read DER encoded OCSP request from \"file\"\n");
    BIO_printf(bio_err,"-respin file       read DER encoded OCSP reponse from \"file\"\n");
    BIO_printf(bio_err,"-nonce             add OCSP nonce to request\n");
    BIO_printf(bio_err,"-no_nonce          don\'t add OCSP nonce to request\n");
    BIO_printf(bio_err,"-url URL           OCSP responder URL\n");
    BIO_printf(bio_err,"-host host:n       send OCSP request to host on port n\n");
    BIO_printf(bio_err,"-path              path to use in OCSP request\n");
    BIO_printf(bio_err,"-CApath dir        trusted certificates directory\n");
    BIO_printf(bio_err,"-CAfile file       trusted certificates file\n");
    BIO_printf(bio_err,"-VAfile file       validator certificates file\n");
    BIO_printf(bio_err,"-validity_period n maximum validity discrepancy in seconds\n");
    BIO_printf(bio_err,"-status_age n      maximum status age in seconds\n");
    BIO_printf(bio_err,"-noverify          don\'t verify response at all\n");
    BIO_printf(bio_err,"-verify_other file additional certificates to search for signer\n");
    BIO_printf(bio_err,"-trust_other       don\'t verify additional certificates\n");
    BIO_printf(bio_err,
               "-no_intern         don\'t search certificates contained in response for signer\n");
    BIO_printf(bio_err,"-no_signature_verify don\'t check signature on response\n");
    BIO_printf(bio_err,"-no_cert_verify    don\'t check signing certificate\n");
    BIO_printf(bio_err,"-no_chain          don\'t chain verify response\n");
    BIO_printf(bio_err,"-no_cert_checks    don\'t do additional checks on signing certificate\n");
    BIO_printf(bio_err,"-port num\t\t port to run responder on\n");
    BIO_printf(bio_err,"-index file\t certificate status index file\n");
    BIO_printf(bio_err,"-CA file\t\t CA certificate\n");
    BIO_printf(bio_err,"-rsigner file\t responder certificate to sign responses with\n");
    BIO_printf(bio_err,"-rkey file\t responder key to sign responses with\n");
    BIO_printf(bio_err,"-rother file\t other certificates to include in response\n");
    BIO_printf(bio_err,"-resp_no_certs     don\'t include any certificates in response\n");
    BIO_printf(bio_err,"-nmin n\t \t number of minutes before next update\n");
    BIO_printf(bio_err,"-ndays n\t \t number of days before next update\n");
    BIO_printf(bio_err,"-resp_key_id       identify reponse by signing certificate key ID\n");
    BIO_printf(bio_err,"-nrequest n        number of requests to accept (default unlimited)\n");
    BIO_printf(bio_err,"-<dgst alg>     use specified digest in the request\n");
LAB_0808effc:
    local_154 = (BIO *)0x0;
  }
  else {
    if (pcVar16 == (char *)0x0) {
      local_154 = BIO_new_fp(stdout,0);
    }
    else {
      local_154 = BIO_new_file(pcVar16,"w");
    }
    pcVar10 = local_bc;
    if (local_154 != (BIO *)0x0) {
      if (local_ac == (OCSP_REQUEST *)0x0) {
        iVar5 = 0;
        if (local_11c == 2) {
          iVar5 = local_11c;
        }
        local_11c = iVar5;
        if (local_16c != (X509 *)0x0) {
          pBVar14 = BIO_new_file((char *)local_16c,"rb");
          if (pBVar14 == (BIO *)0x0) {
            a = (OCSP_RESPONSE *)0x0;
            uVar17 = 1;
            st = (_STACK *)0x0;
            BIO_printf(bio_err,"Error Opening OCSP request file\n");
            local_180 = (X509 *)0x0;
            local_168 = (EVP_MD *)0x0;
            local_17c = (X509_STORE *)0x0;
            local_15c = (BIO *)0x0;
            local_148 = (EVP_PKEY *)0x0;
            local_150 = (EVP_PKEY *)0x0;
            local_14c = (X509 *)0x0;
            local_16c = (X509 *)0x0;
            goto LAB_0808ddcb;
          }
          local_ac = (OCSP_REQUEST *)
                     ASN1_d2i_bio(OCSP_REQUEST_new,d2i_OCSP_REQUEST,pBVar14,(void **)0x0);
          BIO_free(pBVar14);
          if (local_ac == (OCSP_REQUEST *)0x0) {
            pcVar10 = "Error reading OCSP request\n";
            goto LAB_0808f338;
          }
          goto LAB_0808e264;
        }
        if (local_bc == (char *)0x0) goto LAB_0808e264;
        type = BIO_f_buffer();
        pBVar14 = BIO_new(type);
        if (pBVar14 == (BIO *)0x0) {
          local_15c = (BIO *)0x0;
LAB_0808f9ed:
          BIO_free_all(local_15c);
          BIO_free(pBVar14);
          goto LAB_0808f02d;
        }
        local_15c = BIO_new_accept(pcVar10);
        if (local_15c == (BIO *)0x0) goto LAB_0808f9ed;
        BIO_ctrl(local_15c,0x76,2,pBVar14);
        lVar6 = BIO_ctrl(local_15c,0x65,0,(void *)0x0);
        if (lVar6 < 1) {
          pBVar14 = (BIO *)0x0;
          BIO_printf(bio_err,"Error setting up accept BIO\n");
          ERR_print_errors(bio_err);
          goto LAB_0808f9ed;
        }
        if (local_180 != (X509 *)0x0) goto LAB_0808e278;
        local_180 = (X509 *)0x0;
        local_d8 = (stack_st_X509 *)0x0;
        local_148 = (EVP_PKEY *)0x0;
        local_14c = (X509 *)0x0;
LAB_0808e344:
        BIO_printf(bio_err,"Waiting for OCSP client connections...\n");
      }
      else {
LAB_0808e264:
        if (local_180 == (X509 *)0x0) {
          local_180 = (X509 *)0x0;
          local_d8 = (stack_st_X509 *)0x0;
          local_15c = (BIO *)0x0;
          local_148 = (EVP_PKEY *)0x0;
          local_14c = (X509 *)0x0;
        }
        else {
          local_15c = (BIO *)0x0;
LAB_0808e278:
          if (local_17c == (X509_STORE *)0x0) {
            local_17c = (X509_STORE *)local_180;
          }
          local_14c = (X509 *)load_cert(bio_err,local_180,3,0,0,"responder certificate");
          if (local_14c == (X509 *)0x0) {
            BIO_printf(bio_err,"Error loading responder certificate\n");
            local_180 = (X509 *)0x0;
LAB_0808f436:
            a = (OCSP_RESPONSE *)0x0;
            uVar17 = 1;
            st = (_STACK *)0x0;
            local_168 = (EVP_MD *)0x0;
            local_17c = (X509_STORE *)0x0;
            local_148 = (EVP_PKEY *)0x0;
            pBVar14 = (BIO *)0x0;
            local_150 = (EVP_PKEY *)0x0;
            local_16c = (X509 *)0x0;
            goto LAB_0808ddcb;
          }
          local_180 = (X509 *)load_cert(bio_err,local_174,3,0,0,"CA certificate");
          if (local_178 == 0) {
            local_d8 = (stack_st_X509 *)0x0;
          }
          else {
            local_d8 = (stack_st_X509 *)
                       load_certs(bio_err,local_178,3,0,0,"responder other certificates");
            if (local_d8 == (stack_st_X509 *)0x0) goto LAB_0808f436;
          }
          local_148 = (EVP_PKEY *)load_key(bio_err,local_17c,3,0,0,0,"responder private key");
          if (local_148 == (EVP_PKEY *)0x0) {
            a = (OCSP_RESPONSE *)0x0;
            uVar17 = 1;
            st = (_STACK *)0x0;
            local_168 = (EVP_MD *)0x0;
            local_17c = (X509_STORE *)0x0;
            local_150 = (EVP_PKEY *)0x0;
            local_16c = (X509 *)0x0;
            pBVar14 = (BIO *)0x0;
            goto LAB_0808ddcb;
          }
          if (local_15c != (BIO *)0x0) goto LAB_0808e344;
        }
      }
      local_178 = 0;
      local_168 = (EVP_MD *)0x0;
      local_150 = (EVP_PKEY *)0x0;
      local_16c = (X509 *)0x0;
      a = (OCSP_RESPONSE *)0x0;
LAB_0808e3f1:
      if (local_15c == (BIO *)0x0) goto LAB_0808e96b;
LAB_0808e3fd:
      iVar5 = do_responder_isra_0();
      if (iVar5 != 0) {
        if (local_ac == (OCSP_REQUEST *)0x0) {
          a = OCSP_response_create(1,(OCSP_BASICRESP *)0x0);
          pBVar14 = local_a8;
          local_71._0_4_ = s_HTTP_1_0_200_OK_Content_type__ap_081fce20._0_4_;
          local_24 = s_HTTP_1_0_200_OK_Content_type__ap_081fce20._77_4_;
          iVar5 = -(int)(local_71 + 1);
          puVar18 = (undefined4 *)
                    (
                    "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
                    + -(int)(local_71 + iVar5));
          puVar21 = (undefined4 *)(local_71 + 1);
          for (uVar13 = (uint)((int)&local_20 + iVar5) >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *puVar21 = *puVar18;
            puVar18 = puVar18 + (uint)bVar25 * -2 + 1;
            puVar21 = puVar21 + (uint)bVar25 * -2 + 1;
          }
          if (local_a8 == (BIO *)0x0) goto LAB_0808e89e;
          i2d_OCSP_RESPONSE(a,(uchar **)0x0);
          goto LAB_0808e87a;
        }
LAB_0808e429:
        if (local_11c != 0) {
          OCSP_request_add1_nonce(local_ac,(uchar *)0x0,-1);
        }
LAB_0808e435:
        if (local_124 == 0) {
LAB_0808e502:
          if ((bVar1) && (local_ac != (OCSP_REQUEST *)0x0)) {
            OCSP_REQUEST_print(local_154,local_ac,0);
          }
          if (local_120 != (char *)0x0) {
            pBVar14 = BIO_new_file(local_120,"wb");
            if (pBVar14 != (BIO *)0x0) {
              ASN1_i2d_bio(i2d_OCSP_REQUEST,pBVar14,(uchar *)local_ac);
              BIO_free(pBVar14);
              goto LAB_0808e56a;
            }
LAB_0808f62d:
            pcVar10 = "Error opening file %s\n";
LAB_0808f22b:
            uVar17 = 1;
            st = (_STACK *)0x0;
            BIO_printf(bio_err,pcVar10);
            local_17c = (X509_STORE *)0x0;
            goto LAB_0808ddcb;
          }
LAB_0808e56a:
          if (local_12c == 0) {
            if (local_178 != 0) goto LAB_0808e590;
            if (local_c0 != (char *)0x0) {
              a = (OCSP_RESPONSE *)process_responder();
              if (a != (OCSP_RESPONSE *)0x0) goto LAB_0808e89e;
              goto LAB_0808eb20;
            }
            if (local_f4 != (char *)0x0) {
              pBVar14 = BIO_new_file(local_f4,"rb");
              if (pBVar14 != (BIO *)0x0) {
                a = (OCSP_RESPONSE *)
                    ASN1_d2i_bio(OCSP_RESPONSE_new,d2i_OCSP_RESPONSE,pBVar14,(void **)0x0);
                BIO_free(pBVar14);
                if (a == (OCSP_RESPONSE *)0x0) {
                  pcVar10 = "Error reading OCSP response\n";
                  goto LAB_0808f1b9;
                }
                goto LAB_0808e89e;
              }
              pcVar10 = "Error Opening OCSP response file\n";
              goto LAB_0808f22b;
            }
LAB_0808eb6b:
            uVar17 = 0;
            st = (_STACK *)0x0;
            local_17c = (X509_STORE *)0x0;
            pBVar14 = (BIO *)0x0;
            goto LAB_0808ddcb;
          }
          if ((local_14c == (X509 *)0x0 || local_148 == (EVP_PKEY *)0x0) || local_180 == (X509 *)0x0
             ) {
            pcVar10 = "Need a responder certificate, key and CA for this operation!\n";
            goto LAB_0808f1b9;
          }
          if ((local_178 == 0) &&
             ((local_178 = load_index(), local_178 == 0 || (iVar5 = index_index(), iVar5 == 0))))
          goto LAB_0808eb20;
LAB_0808e590:
          req = local_ac;
          iVar5 = OCSP_request_onereq_count(local_ac);
          if (iVar5 < 1) {
            pOVar20 = (OCSP_CERTID *)0x0;
            a = OCSP_response_create(1,(OCSP_BASICRESP *)0x0);
            local_164 = (OCSP_BASICRESP *)0x0;
            local_160 = (ASN1_TIME *)0x0;
            local_158 = (ASN1_TIME *)0x0;
          }
          else {
            local_164 = OCSP_BASICRESP_new();
            local_158 = X509_gmtime_adj((ASN1_TIME *)0x0,0);
            local_160 = (ASN1_TIME *)0x0;
            if (local_108 != -1) {
              local_160 = X509_gmtime_adj((ASN1_TIME *)0x0,local_170 * 0x3c + local_108 * 0x15180);
            }
            pOVar20 = (OCSP_CERTID *)0x0;
            iVar12 = 0;
            do {
              while( true ) {
                pOVar8 = OCSP_request_onereq_get0(req,iVar12);
                cid = OCSP_onereq_get0_id(pOVar8);
                OCSP_id_get0_info((ASN1_OCTET_STRING **)0x0,&local_a0,(ASN1_OCTET_STRING **)0x0,
                                  (ASN1_INTEGER **)0x0,cid);
                iVar9 = OBJ_obj2nid(local_a0);
                pcVar10 = OBJ_nid2sn(iVar9);
                dgst = EVP_get_digestbyname(pcVar10);
                if (dgst == (EVP_MD *)0x0) {
                  a = OCSP_response_create(2,(OCSP_BASICRESP *)0x0);
                  goto LAB_0808e802;
                }
                if (pOVar20 != (OCSP_CERTID *)0x0) {
                  OCSP_CERTID_free(pOVar20);
                }
                pOVar20 = OCSP_cert_to_id(dgst,(X509 *)0x0,local_180);
                iVar9 = OCSP_id_issuer_cmp(pOVar20,cid);
                if (iVar9 == 0) break;
LAB_0808e799:
                iVar12 = iVar12 + 1;
                OCSP_basic_add1_status(local_164,cid,2,0,(ASN1_TIME *)0x0,local_158,local_160);
                if (iVar5 == iVar12) goto LAB_0808e7c4;
              }
              OCSP_id_get0_info((ASN1_OCTET_STRING **)0x0,(ASN1_OBJECT **)0x0,
                                (ASN1_OCTET_STRING **)0x0,&local_a4,cid);
              local_8c = (OPENSSL_STRING)0x0;
              local_88 = 0;
              local_84 = 0;
              local_80 = (char *)0x0;
              local_7c = 0;
              local_78 = 0;
              local_17c = (X509_STORE *)ASN1_INTEGER_to_BN(local_a4,(BIGNUM *)0x0);
              if (local_17c == (X509_STORE *)0x0) {
                local_17c = (X509_STORE *)0x0;
                OpenSSLDie("ocsp.c",0x48d,"bn");
              }
              if (((BIGNUM *)local_17c)->top == 0) {
                pcVar10 = BUF_strdup("00");
              }
              else {
                pcVar10 = BN_bn2hex((BIGNUM *)local_17c);
              }
              local_80 = pcVar10;
              BN_free((BIGNUM *)local_17c);
              ppcVar7 = TXT_DB_get_by_index(*(TXT_DB **)(local_178 + 4),3,&local_8c);
              CRYPTO_free(pcVar10);
              if (ppcVar7 == (OPENSSL_STRING *)0x0) goto LAB_0808e799;
              if (**ppcVar7 == 'V') {
                OCSP_basic_add1_status(local_164,cid,0,0,(ASN1_TIME *)0x0,local_158,local_160);
              }
              else if (**ppcVar7 == 'R') {
                local_9c = (ASN1_OBJECT *)0x0;
                local_98 = (ASN1_TIME *)0x0;
                local_94 = (ASN1_GENERALIZEDTIME *)0x0;
                local_90 = (ASN1_GENERALIZEDTIME *)0xffffffff;
                unpack_revinfo();
                x = OCSP_basic_add1_status
                              (local_164,cid,1,(int)local_90,local_98,local_158,local_160);
                if (local_94 == (ASN1_GENERALIZEDTIME *)0x0) {
                  if (local_9c != (ASN1_OBJECT *)0x0) {
                    OCSP_SINGLERESP_add1_ext_i2d(x,0x1ae,local_9c,0,0);
                  }
                }
                else {
                  OCSP_SINGLERESP_add1_ext_i2d(x,0x8e,local_94,0,0);
                }
                ASN1_OBJECT_free(local_9c);
                ASN1_TIME_free(local_98);
                ASN1_GENERALIZEDTIME_free(local_94);
              }
              iVar12 = iVar12 + 1;
            } while (iVar5 != iVar12);
LAB_0808e7c4:
            OCSP_copy_nonce(local_164,req);
            OCSP_basic_sign(local_164,local_14c,local_148,(EVP_MD *)0x0,local_d8,local_fc);
            a = OCSP_response_create(0,local_164);
          }
LAB_0808e802:
          ASN1_TIME_free(local_158);
          ASN1_TIME_free(local_160);
          OCSP_CERTID_free(pOVar20);
          OCSP_BASICRESP_free(local_164);
          pBVar14 = local_a8;
          if (local_a8 != (BIO *)0x0) {
            local_71._0_4_ = s_HTTP_1_0_200_OK_Content_type__ap_081fce20._0_4_;
            local_24 = s_HTTP_1_0_200_OK_Content_type__ap_081fce20._77_4_;
            puVar18 = (undefined4 *)0x81fce21;
            puVar21 = (undefined4 *)(local_71 + 1);
            for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar21 = *puVar18;
              puVar18 = puVar18 + (uint)bVar25 * -2 + 1;
              puVar21 = puVar21 + (uint)bVar25 * -2 + 1;
            }
            i2d_OCSP_RESPONSE(a,(uchar **)0x0);
LAB_0808e87a:
            BIO_printf(pBVar14,local_71);
            ASN1_i2d_bio(i2d_OCSP_RESPONSE,pBVar14,(uchar *)a);
            BIO_ctrl(pBVar14,0xb,0,(void *)0x0);
          }
LAB_0808e89e:
          if (local_118 != (char *)0x0) {
            pBVar14 = BIO_new_file(local_118,"wb");
            if (pBVar14 == (BIO *)0x0) goto LAB_0808f62d;
            ASN1_i2d_bio(i2d_OCSP_RESPONSE,pBVar14,(uchar *)a);
            BIO_free(pBVar14);
          }
          iVar5 = OCSP_response_status(a);
          if (iVar5 != 0) {
            OCSP_response_status_str(iVar5);
            BIO_printf(local_154,"Responder Error: %s (%d)\n");
            if (!bVar3) goto LAB_0808eb6b;
            goto LAB_0808e3f1;
          }
          if (bVar2) {
            OCSP_RESPONSE_print(local_154,a,0);
          }
          if (local_a8 == (BIO *)0x0) {
            local_17c = (X509_STORE *)setup_verify();
            if (local_17c == (X509_STORE *)0x0) {
              uVar17 = 1;
              st = (_STACK *)0x0;
              pBVar14 = (BIO *)0x0;
              goto LAB_0808ddcb;
            }
            if (local_f0 == 0) {
              st = (_STACK *)0x0;
            }
            else {
              st = (_STACK *)load_certs();
              if (st == (_STACK *)0x0) {
                uVar17 = 1;
                pBVar14 = (BIO *)0x0;
                goto LAB_0808ddcb;
              }
            }
            pBVar14 = (BIO *)OCSP_response_get1_basic(a);
            if (pBVar14 == (BIO *)0x0) {
              uVar17 = 1;
              BIO_printf(bio_err,"Error parsing response\n");
              goto LAB_0808ddcb;
            }
            if (!bVar4) {
              if ((local_ac != (OCSP_REQUEST *)0x0) &&
                 (iVar5 = OCSP_check_nonce(local_ac,(OCSP_BASICRESP *)pBVar14), iVar5 < 1)) {
                if (iVar5 != -1) {
                  uVar17 = 1;
                  BIO_printf(bio_err,"Nonce Verify error\n");
                  goto LAB_0808ddcb;
                }
                BIO_printf(bio_err,"WARNING: no nonce in response\n");
              }
              iVar5 = OCSP_basic_verify((OCSP_BASICRESP *)pBVar14,(stack_st_X509 *)st,local_17c,
                                        local_f8);
              if (iVar5 < 0) {
                iVar5 = OCSP_basic_verify((OCSP_BASICRESP *)pBVar14,(stack_st_X509 *)0x0,local_17c,0
                                         );
              }
              if (iVar5 < 1) {
                BIO_printf(bio_err,"Response Verify Failure\n");
                ERR_print_errors(bio_err);
              }
              else {
                BIO_printf(bio_err,"Response verify OK\n");
              }
            }
            if (((local_ac == (OCSP_REQUEST *)0x0) || (iVar5 = sk_num(local_138), iVar5 == 0)) ||
               (iVar5 = sk_num(local_140), iVar5 == 0)) {
              uVar17 = 0;
            }
            else {
              for (iVar5 = 0; iVar12 = sk_num(local_140), iVar5 < iVar12; iVar5 = iVar5 + 1) {
                pOVar20 = (OCSP_CERTID *)sk_value(local_140,iVar5);
                sk_value(local_138,iVar5);
                BIO_printf(local_154,"%s: ");
                iVar12 = OCSP_resp_find_status
                                   ((OCSP_BASICRESP *)pBVar14,pOVar20,(int *)&local_a0,
                                    (int *)&local_9c,&local_98,&local_94,&local_90);
                if (iVar12 == 0) {
                  BIO_puts(local_154,"ERROR: No Status found.\n");
                }
                else {
                  iVar12 = OCSP_check_validity(local_94,local_90,local_e8,local_e4);
                  if (iVar12 == 0) {
                    BIO_puts(local_154,"WARNING: Status times invalid.\n");
                    ERR_print_errors(local_154);
                  }
                  OCSP_cert_status_str((long)local_a0);
                  BIO_printf(local_154,"%s\n");
                  BIO_puts(local_154,"\tThis Update: ");
                  ASN1_GENERALIZEDTIME_print(local_154,local_94);
                  BIO_puts(local_154,"\n");
                  if (local_90 != (ASN1_GENERALIZEDTIME *)0x0) {
                    BIO_puts(local_154,"\tNext Update: ");
                    ASN1_GENERALIZEDTIME_print(local_154,local_90);
                    BIO_puts(local_154,"\n");
                  }
                  if (local_a0 == (ASN1_OBJECT *)0x1) {
                    if (local_9c != (ASN1_OBJECT *)0xffffffff) {
                      OCSP_crl_reason_str((long)local_9c);
                      BIO_printf(local_154,"\tReason: %s\n");
                    }
                    BIO_puts(local_154,"\tRevocation Time: ");
                    ASN1_GENERALIZEDTIME_print(local_154,local_98);
                    BIO_puts(local_154,"\n");
                  }
                }
              }
              uVar17 = 0;
            }
            goto LAB_0808ddcb;
          }
          local_128 = local_128 - (uint)(0 < local_128);
          if (local_128 == 0) goto LAB_0808eb20;
          BIO_free_all(local_a8);
          local_a8 = (BIO *)0x0;
          OCSP_REQUEST_free(local_ac);
          local_ac = (OCSP_REQUEST *)0x0;
          OCSP_RESPONSE_free(a);
          a = (OCSP_RESPONSE *)0x0;
          if (local_15c != (BIO *)0x0) goto LAB_0808e3fd;
LAB_0808e96b:
          if (local_ac == (OCSP_REQUEST *)0x0) goto code_r0x0808e97a;
          goto LAB_0808e429;
        }
        if (local_134 == 0) {
          local_134 = local_124;
        }
        local_16c = (X509 *)load_cert();
        if (local_16c == (X509 *)0x0) {
          pcVar10 = "Error loading signer certificate\n";
          goto LAB_0808f1b9;
        }
        if (((local_110 != 0) && (local_168 = (EVP_MD *)load_certs(), local_168 == (EVP_MD *)0x0))
           || (local_150 = (EVP_PKEY *)load_key(), local_150 == (EVP_PKEY *)0x0)) goto LAB_0808eb20;
        iVar5 = OCSP_request_sign(local_ac,local_16c,local_150,(EVP_MD *)0x0,
                                  (stack_st_X509 *)local_168,local_10c);
        if (iVar5 != 0) goto LAB_0808e502;
        pcVar10 = "Error signing OCSP request\n";
        goto LAB_0808f1b9;
      }
LAB_0808eb20:
      uVar17 = 1;
      st = (_STACK *)0x0;
      local_17c = (X509_STORE *)0x0;
      pBVar14 = (BIO *)0x0;
      goto LAB_0808ddcb;
    }
    pcVar10 = "Error opening output file\n";
LAB_0808f338:
    BIO_printf(bio_err,pcVar10);
  }
LAB_0808f02d:
  local_168 = (EVP_MD *)0x0;
  local_17c = (X509_STORE *)0x0;
  local_180 = (X509 *)0x0;
  st = (_STACK *)0x0;
  a = (OCSP_RESPONSE *)0x0;
  uVar17 = 1;
  local_15c = (BIO *)0x0;
  local_148 = (EVP_PKEY *)0x0;
  pBVar14 = (BIO *)0x0;
  local_150 = (EVP_PKEY *)0x0;
  local_14c = (X509 *)0x0;
  local_16c = (X509 *)0x0;
LAB_0808ddcb:
  ERR_print_errors(bio_err);
  X509_free(local_16c);
  X509_STORE_free(local_17c);
  EVP_PKEY_free(local_150);
  EVP_PKEY_free(local_148);
  X509_free(local_144);
  X509_free(local_13c);
  X509_free(local_14c);
  X509_free(local_180);
  free_index();
  BIO_free_all(local_a8);
  BIO_free_all(local_15c);
  BIO_free(local_154);
  OCSP_REQUEST_free(local_ac);
  OCSP_RESPONSE_free(a);
  OCSP_BASICRESP_free((OCSP_BASICRESP *)pBVar14);
  sk_free(local_138);
  sk_free(local_140);
  sk_pop_free((_STACK *)local_168,X509_free);
  sk_pop_free(st,X509_free);
  sk_pop_free(local_b0,X509V3_conf_free);
  if (local_b4 != -1) {
    CRYPTO_free(local_c0);
    CRYPTO_free(local_bc);
    CRYPTO_free(local_b8);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar17;
code_r0x0808e97a:
  if (((local_124 == 0 && local_120 == (char *)0x0) && (local_c0 == (char *)0x0)) &&
     (local_11c == 0 && local_12c == 0)) goto LAB_0808e435;
  pcVar10 = "Need an OCSP request for this operation!\n";
LAB_0808f1b9:
  BIO_printf(bio_err,pcVar10);
  goto LAB_0808eb20;
}

