
/* WARNING: Type propagation algorithm not settling */

undefined4 req_main(int param_1,undefined4 *param_2)

{
  byte bVar1;
  X509_REQ_INFO *pXVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  EVP_CIPHER *pEVar13;
  char *pcVar14;
  BIO *pBVar15;
  BIO_METHOD *pBVar16;
  undefined4 uVar17;
  char *pcVar18;
  long lVar19;
  X509_NAME *pXVar20;
  byte *pbVar21;
  FILE *pFVar22;
  _STACK *p_Var23;
  FILE *section;
  void *pvVar24;
  int iVar25;
  FILE *src;
  uint *puVar26;
  uint *puVar27;
  char *pcVar28;
  ulong uVar29;
  EVP_MD *pEVar30;
  ASN1_TIME *pAVar31;
  ASN1_INTEGER *pAVar32;
  int iVar33;
  byte *pbVar34;
  uint uVar35;
  uint uVar36;
  char **ppcVar37;
  EVP_PKEY *pEVar38;
  char **ppcVar39;
  X509_REQ *x;
  X509 *x_00;
  int in_GS_OFFSET;
  bool bVar40;
  bool bVar41;
  byte bVar42;
  int local_570;
  int local_56c;
  char *local_568;
  ENGINE *local_564;
  BIO *local_560;
  _STACK *local_55c;
  char *local_558;
  char *local_554;
  _STACK *local_550;
  ASN1_INTEGER *local_54c;
  char *local_548;
  char *local_53c;
  char *local_538;
  int local_534;
  char *local_530;
  FILE *local_528;
  char *local_520;
  int local_518;
  char *local_514;
  EVP_CIPHER *local_50c;
  EVP_MD *local_508;
  _STACK *local_504;
  char *local_4fc;
  undefined4 local_4f8;
  FILE *local_4f0;
  long local_4ec;
  undefined4 local_4e4;
  char *local_4d8;
  ulong local_4c4;
  ulong local_4c0;
  void *local_4bc;
  EVP_PKEY *local_4b8;
  int local_4b4;
  int local_4b0;
  char *local_4ac;
  FILE *local_4a8;
  long local_4a4;
  X509V3_CTX local_4a0;
  char local_484 [96];
  uchar auStack_424 [4];
  char local_420;
  char cStack_41f;
  int local_20;
  
  bVar42 = 0;
  req_conf = (CONF *)0x0;
  local_4c4 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_4c0 = 0;
  local_4bc = (void *)0x0;
  local_4b8 = (EVP_PKEY *)0x0;
  local_4b4 = -1;
  local_4b0 = -1;
  local_4ac = (char *)0x0;
  local_4a8 = (FILE *)0x0;
  pEVar13 = EVP_des_ede3_cbc();
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar16 = BIO_s_file();
    bio_err = BIO_new(pBVar16);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  uVar17 = *param_2;
  ppcVar37 = (char **)(param_2 + 1);
  local_534 = 0x1001;
  param_1 = param_1 + -1;
  bVar40 = param_1 == 0;
  if (param_1 < 1) {
    local_4f8 = 0;
    local_538 = (char *)0x0;
    local_554 = (char *)0x0;
    local_558 = (char *)0x0;
    local_4d8 = (char *)0x0;
    bVar9 = false;
    local_54c = (ASN1_INTEGER *)0x0;
    local_528 = (FILE *)0x0;
    local_530 = (char *)0x0;
    local_568 = (char *)0x0;
    local_514 = (char *)0x0;
    local_53c = (char *)0x0;
    local_548 = (char *)0x0;
    local_520 = (char *)0x0;
    local_4fc = (char *)0x0;
    bVar8 = false;
    bVar10 = false;
    bVar11 = false;
    local_518 = 0;
    bVar12 = false;
    local_4e4 = 3;
    bVar7 = false;
    bVar6 = false;
    bVar3 = 0;
    local_56c = 3;
    local_570 = 3;
    bVar4 = false;
    bVar41 = false;
    local_550 = (_STACK *)0x0;
    local_55c = (_STACK *)0x0;
    local_504 = (_STACK *)0x0;
    local_4ec = 0x1e;
    bVar5 = false;
    local_564 = (ENGINE *)0x0;
    local_508 = (EVP_MD *)0x0;
    local_4f0 = (FILE *)0x0;
  }
  else {
    local_508 = (EVP_MD *)0x0;
    local_4f0 = (FILE *)0x0;
    local_4f8 = 0;
    local_538 = (char *)0x0;
    local_554 = (char *)0x0;
    local_558 = (char *)0x0;
    local_4d8 = (char *)0x0;
    bVar9 = false;
    local_54c = (ASN1_INTEGER *)0x0;
    local_528 = (FILE *)0x0;
    local_530 = (char *)0x0;
    local_568 = (char *)0x0;
    local_514 = (char *)0x0;
    local_53c = (char *)0x0;
    local_548 = (char *)0x0;
    local_520 = (char *)0x0;
    local_4fc = (char *)0x0;
    bVar8 = false;
    bVar10 = false;
    bVar11 = false;
    local_518 = 0;
    bVar12 = false;
    local_4e4 = 3;
    bVar7 = false;
    bVar6 = false;
    bVar3 = 0;
    local_56c = 3;
    local_570 = 3;
    bVar4 = false;
    bVar41 = false;
    local_550 = (_STACK *)0x0;
    local_55c = (_STACK *)0x0;
    local_504 = (_STACK *)0x0;
    local_4ec = 0x1e;
    bVar5 = false;
    local_564 = (ENGINE *)0x0;
LAB_0804e126:
    do {
      pcVar14 = *ppcVar37;
      iVar33 = 8;
      pcVar18 = pcVar14;
      pcVar28 = "-inform";
      do {
        if (iVar33 == 0) break;
        iVar33 = iVar33 + -1;
        bVar40 = *pcVar18 == *pcVar28;
        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
        pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
      } while (bVar40);
      if (bVar40) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          local_570 = str2fmt(ppcVar37[1]);
          ppcVar39 = ppcVar37 + 1;
          goto LAB_0804e11e;
        }
LAB_0804e600:
        BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar17);
        BIO_printf(bio_err,"where options  are\n");
        BIO_printf(bio_err," -inform arg    input format - DER or PEM\n");
        BIO_printf(bio_err," -outform arg   output format - DER or PEM\n");
        BIO_printf(bio_err," -in arg        input file\n");
        BIO_printf(bio_err," -out arg       output file\n");
        BIO_printf(bio_err," -text          text form of request\n");
        BIO_printf(bio_err," -pubkey        output public key\n");
        BIO_printf(bio_err," -noout         do not output REQ\n");
        BIO_printf(bio_err," -verify        verify signature on REQ\n");
        BIO_printf(bio_err," -modulus       RSA modulus\n");
        BIO_printf(bio_err," -nodes         don\'t encrypt the output key\n");
        BIO_printf(bio_err," -engine e      use engine e, possibly a hardware device\n");
        BIO_printf(bio_err," -subject       output the request\'s subject\n");
        BIO_printf(bio_err," -passin        private key password source\n");
        BIO_printf(bio_err," -key file      use the private key contained in file\n");
        BIO_printf(bio_err," -keyform arg   key file format\n");
        BIO_printf(bio_err," -keyout arg    file to send the key to\n");
        BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
        BIO_printf(bio_err,"                load the file (or the files in the directory) into\n");
        BIO_printf(bio_err,"                the random number generator\n");
        BIO_printf(bio_err," -newkey rsa:bits generate a new RSA key of \'bits\' in size\n");
        BIO_printf(bio_err,
                   " -newkey dsa:file generate a new DSA key, parameters taken from CA in \'file\'\n"
                  );
        BIO_printf(bio_err,
                   " -newkey ec:file generate a new EC key, parameters taken from CA in \'file\'\n")
        ;
        BIO_printf(bio_err," -[digest]      Digest to sign with (md5, sha1, md2, mdc2, md4)\n");
        BIO_printf(bio_err," -config file   request template file.\n");
        BIO_printf(bio_err," -subj arg      set or modify request subject\n");
        BIO_printf(bio_err," -multivalue-rdn enable support for multivalued RDNs\n");
        BIO_printf(bio_err," -new           new request.\n");
        BIO_printf(bio_err," -batch         do not ask anything during request generation\n");
        BIO_printf(bio_err," -x509          output a x509 structure instead of a cert. req.\n");
        BIO_printf(bio_err,
                   " -days          number of days a certificate generated by -x509 is valid for.\n"
                  );
        BIO_printf(bio_err,
                   " -set_serial    serial number to use for a certificate generated by -x509.\n");
        BIO_printf(bio_err," -newhdr        output \"NEW\" in the header lines\n");
        BIO_printf(bio_err,
                   " -asn1-kludge   Output the \'request\' in a format that is wrong but some CA\'s\n"
                  );
        BIO_printf(bio_err,"                have been reported as requiring\n");
        BIO_printf(bio_err,
                   " -extensions .. specify certificate extension section (override value in config file)\n"
                  );
        BIO_printf(bio_err,
                   " -reqexts ..    specify request extension section (override value in config file)\n"
                  );
        BIO_printf(bio_err," -utf8          input characters are UTF8 (default ASCII)\n");
        BIO_printf(bio_err," -nameopt arg    - various certificate name options\n");
        pcVar14 = " -reqopt arg    - various request text options\n\n";
        goto LAB_0804e8df;
      }
      iVar33 = 9;
      pcVar18 = pcVar14;
      pcVar28 = "-outform";
      do {
        if (iVar33 == 0) break;
        iVar33 = iVar33 + -1;
        bVar40 = *pcVar18 == *pcVar28;
        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
        pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
      } while (bVar40);
      if (!bVar40) {
        iVar33 = 8;
        pcVar18 = pcVar14;
        pcVar28 = "-engine";
        do {
          if (iVar33 == 0) break;
          iVar33 = iVar33 + -1;
          bVar40 = *pcVar18 == *pcVar28;
          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
          pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
        } while (bVar40);
        if (bVar40) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0804e600;
          local_568 = ppcVar37[1];
          ppcVar39 = ppcVar37 + 1;
        }
        else {
          iVar33 = 0xf;
          pcVar18 = pcVar14;
          pcVar28 = "-keygen_engine";
          do {
            if (iVar33 == 0) break;
            iVar33 = iVar33 + -1;
            bVar40 = *pcVar18 == *pcVar28;
            pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
            pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
          } while (bVar40);
          if (bVar40) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0804e600;
            local_564 = ENGINE_by_id(pcVar14);
            ppcVar39 = ppcVar37 + 1;
            if (local_564 == (ENGINE *)0x0) {
              pcVar14 = "Can\'t find keygen engine %s\n";
              goto LAB_0804e8df;
            }
          }
          else {
            iVar33 = 5;
            pcVar18 = pcVar14;
            pcVar28 = "-key";
            do {
              if (iVar33 == 0) break;
              iVar33 = iVar33 + -1;
              bVar40 = *pcVar18 == *pcVar28;
              pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
              pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
            } while (bVar40);
            if (bVar40) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0804e600;
              local_548 = ppcVar37[1];
              ppcVar39 = ppcVar37 + 1;
            }
            else {
              iVar33 = 8;
              pcVar18 = pcVar14;
              pcVar28 = "-pubkey";
              do {
                if (iVar33 == 0) break;
                iVar33 = iVar33 + -1;
                bVar40 = *pcVar18 == *pcVar28;
                pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
              } while (bVar40);
              ppcVar39 = ppcVar37;
              if (bVar40) {
                bVar8 = true;
              }
              else {
                iVar33 = 5;
                pcVar18 = pcVar14;
                pcVar28 = "-new";
                do {
                  if (iVar33 == 0) break;
                  iVar33 = iVar33 + -1;
                  bVar40 = *pcVar18 == *pcVar28;
                  pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                  pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                } while (bVar40);
                if (!bVar40) {
                  iVar33 = 8;
                  pcVar18 = pcVar14;
                  pcVar28 = "-config";
                  do {
                    if (iVar33 == 0) break;
                    iVar33 = iVar33 + -1;
                    bVar40 = *pcVar18 == *pcVar28;
                    pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                    pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                  } while (bVar40);
                  if (bVar40) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      local_53c = ppcVar37[1];
                      ppcVar39 = ppcVar37 + 1;
                      goto LAB_0804e11e;
                    }
                  }
                  else {
                    iVar33 = 9;
                    pcVar18 = pcVar14;
                    pcVar28 = "-keyform";
                    do {
                      if (iVar33 == 0) break;
                      iVar33 = iVar33 + -1;
                      bVar40 = *pcVar18 == *pcVar28;
                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                      pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                    } while (bVar40);
                    if (bVar40) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_4e4 = str2fmt(ppcVar37[1]);
                        ppcVar39 = ppcVar37 + 1;
                        goto LAB_0804e11e;
                      }
                    }
                    else {
                      bVar40 = *pcVar14 == '-';
                      if ((((bVar40) && (bVar40 = pcVar14[1] == 'i', bVar40)) &&
                          (bVar40 = pcVar14[2] == 'n', bVar40)) &&
                         (bVar40 = pcVar14[3] == '\0', bVar40)) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          local_4fc = ppcVar37[1];
                          ppcVar39 = ppcVar37 + 1;
                          goto LAB_0804e11e;
                        }
                      }
                      else {
                        iVar33 = 5;
                        pcVar18 = pcVar14;
                        pcVar28 = "-out";
                        do {
                          if (iVar33 == 0) break;
                          iVar33 = iVar33 + -1;
                          bVar40 = *pcVar18 == *pcVar28;
                          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                          pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                        } while (bVar40);
                        if (bVar40) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_520 = ppcVar37[1];
                            ppcVar39 = ppcVar37 + 1;
                            goto LAB_0804e11e;
                          }
                        }
                        else {
                          iVar33 = 8;
                          pcVar18 = pcVar14;
                          pcVar28 = "-keyout";
                          do {
                            if (iVar33 == 0) break;
                            iVar33 = iVar33 + -1;
                            bVar40 = *pcVar18 == *pcVar28;
                            pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                            pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                          } while (bVar40);
                          if (bVar40) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_514 = ppcVar37[1];
                              ppcVar39 = ppcVar37 + 1;
                              goto LAB_0804e11e;
                            }
                          }
                          else {
                            iVar33 = 8;
                            pcVar18 = pcVar14;
                            pcVar28 = "-passin";
                            do {
                              if (iVar33 == 0) break;
                              iVar33 = iVar33 + -1;
                              bVar40 = *pcVar18 == *pcVar28;
                              pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                              pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                            } while (bVar40);
                            if (bVar40) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_558 = ppcVar37[1];
                                ppcVar39 = ppcVar37 + 1;
                                goto LAB_0804e11e;
                              }
                            }
                            else {
                              iVar33 = 9;
                              pcVar18 = pcVar14;
                              pcVar28 = "-passout";
                              do {
                                if (iVar33 == 0) break;
                                iVar33 = iVar33 + -1;
                                bVar40 = *pcVar18 == *pcVar28;
                                pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                              } while (bVar40);
                              if (bVar40) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_554 = ppcVar37[1];
                                  ppcVar39 = ppcVar37 + 1;
                                  goto LAB_0804e11e;
                                }
                              }
                              else {
                                iVar33 = 6;
                                pcVar18 = pcVar14;
                                pcVar28 = "-rand";
                                do {
                                  if (iVar33 == 0) break;
                                  iVar33 = iVar33 + -1;
                                  bVar40 = *pcVar18 == *pcVar28;
                                  pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                  pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                } while (bVar40);
                                if (bVar40) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_4d8 = ppcVar37[1];
                                    ppcVar39 = ppcVar37 + 1;
                                    goto LAB_0804e11e;
                                  }
                                }
                                else {
                                  iVar33 = 8;
                                  pcVar18 = pcVar14;
                                  pcVar28 = "-newkey";
                                  do {
                                    if (iVar33 == 0) break;
                                    iVar33 = iVar33 + -1;
                                    bVar40 = *pcVar18 == *pcVar28;
                                    pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                    pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                  } while (bVar40);
                                  if (bVar40) {
                                    param_1 = param_1 + -1;
                                    if (param_1 != 0) {
                                      local_504 = (_STACK *)ppcVar37[1];
                                      bVar41 = true;
                                      ppcVar39 = ppcVar37 + 1;
                                      goto LAB_0804e11e;
                                    }
                                  }
                                  else {
                                    iVar33 = 9;
                                    pcVar18 = pcVar14;
                                    pcVar28 = "-pkeyopt";
                                    do {
                                      if (iVar33 == 0) break;
                                      iVar33 = iVar33 + -1;
                                      bVar40 = *pcVar18 == *pcVar28;
                                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                      pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                    } while (bVar40);
                                    if (bVar40) {
                                      if ((param_1 != 1) &&
                                         ((local_55c != (_STACK *)0x0 ||
                                          (local_55c = sk_new_null(), local_55c != (_STACK *)0x0))))
                                      {
                                        pAVar32 = (ASN1_INTEGER *)sk_push(local_55c,ppcVar37[1]);
joined_r0x08050d84:
                                        param_1 = param_1 + -1;
                                        ppcVar39 = ppcVar37 + 1;
                                        if (pAVar32 != (ASN1_INTEGER *)0x0) goto LAB_0804e11e;
                                      }
                                    }
                                    else {
                                      iVar33 = 8;
                                      pcVar18 = pcVar14;
                                      pcVar28 = "-sigopt";
                                      do {
                                        if (iVar33 == 0) break;
                                        iVar33 = iVar33 + -1;
                                        bVar40 = *pcVar18 == *pcVar28;
                                        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                        pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                      } while (bVar40);
                                      if (!bVar40) {
                                        iVar33 = 7;
                                        pcVar18 = pcVar14;
                                        pcVar28 = "-batch";
                                        do {
                                          if (iVar33 == 0) break;
                                          iVar33 = iVar33 + -1;
                                          bVar40 = *pcVar18 == *pcVar28;
                                          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                          pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                        } while (bVar40);
                                        if (bVar40) {
                                          batch = 1;
                                        }
                                        else {
                                          iVar33 = 8;
                                          pcVar18 = pcVar14;
                                          pcVar28 = "-newhdr";
                                          do {
                                            if (iVar33 == 0) break;
                                            iVar33 = iVar33 + -1;
                                            bVar40 = *pcVar18 == *pcVar28;
                                            pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                            pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                          } while (bVar40);
                                          if (bVar40) {
                                            bVar11 = true;
                                          }
                                          else {
                                            iVar33 = 9;
                                            pcVar18 = pcVar14;
                                            pcVar28 = "-modulus";
                                            do {
                                              if (iVar33 == 0) break;
                                              iVar33 = iVar33 + -1;
                                              bVar40 = *pcVar18 == *pcVar28;
                                              pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                              pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                            } while (bVar40);
                                            if (bVar40) {
                                              bVar9 = true;
                                            }
                                            else {
                                              iVar33 = 8;
                                              pcVar18 = pcVar14;
                                              pcVar28 = "-verify";
                                              do {
                                                if (iVar33 == 0) break;
                                                iVar33 = iVar33 + -1;
                                                bVar40 = *pcVar18 == *pcVar28;
                                                pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                              } while (bVar40);
                                              if (bVar40) {
                                                bVar3 = 1;
                                              }
                                              else {
                                                iVar33 = 7;
                                                pcVar18 = pcVar14;
                                                pcVar28 = "-nodes";
                                                do {
                                                  if (iVar33 == 0) break;
                                                  iVar33 = iVar33 + -1;
                                                  bVar40 = *pcVar18 == *pcVar28;
                                                  pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                  pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                } while (bVar40);
                                                if (bVar40) {
                                                  bVar12 = true;
                                                }
                                                else {
                                                  iVar33 = 7;
                                                  pcVar18 = pcVar14;
                                                  pcVar28 = "-noout";
                                                  do {
                                                    if (iVar33 == 0) break;
                                                    iVar33 = iVar33 + -1;
                                                    bVar40 = *pcVar18 == *pcVar28;
                                                    pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                    pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                  } while (bVar40);
                                                  if (bVar40) {
                                                    bVar6 = true;
                                                  }
                                                  else {
                                                    iVar33 = 9;
                                                    pcVar18 = pcVar14;
                                                    pcVar28 = "-verbose";
                                                    do {
                                                      if (iVar33 == 0) break;
                                                      iVar33 = iVar33 + -1;
                                                      bVar40 = *pcVar18 == *pcVar28;
                                                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                      pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                    } while (bVar40);
                                                    if (bVar40) {
                                                      bVar4 = true;
                                                    }
                                                    else {
                                                      iVar33 = 6;
                                                      pcVar18 = pcVar14;
                                                      pcVar28 = "-utf8";
                                                      do {
                                                        if (iVar33 == 0) break;
                                                        iVar33 = iVar33 + -1;
                                                        bVar40 = *pcVar18 == *pcVar28;
                                                        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                        pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                      } while (bVar40);
                                                      if (!bVar40) {
                                                        iVar33 = 9;
                                                        pcVar18 = pcVar14;
                                                        pcVar28 = "-nameopt";
                                                        do {
                                                          if (iVar33 == 0) break;
                                                          iVar33 = iVar33 + -1;
                                                          bVar40 = *pcVar18 == *pcVar28;
                                                          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                          pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                        } while (bVar40);
                                                        if (bVar40) {
                                                          if (param_1 != 1) {
                                                            pAVar32 = (ASN1_INTEGER *)
                                                                      set_name_ex(&local_4c4,
                                                                                  ppcVar37[1]);
                                                            goto joined_r0x08050d84;
                                                          }
                                                        }
                                                        else {
                                                          iVar33 = 8;
                                                          pcVar18 = pcVar14;
                                                          pcVar28 = "-reqopt";
                                                          do {
                                                            if (iVar33 == 0) break;
                                                            iVar33 = iVar33 + -1;
                                                            bVar40 = *pcVar18 == *pcVar28;
                                                            pcVar18 = pcVar18 + (uint)bVar42 * -2 +
                                                                                1;
                                                            pcVar28 = pcVar28 + (uint)bVar42 * -2 +
                                                                                1;
                                                          } while (bVar40);
                                                          if (!bVar40) {
                                                            iVar33 = 9;
                                                            pcVar18 = pcVar14;
                                                            pcVar28 = "-subject";
                                                            do {
                                                              if (iVar33 == 0) break;
                                                              iVar33 = iVar33 + -1;
                                                              bVar40 = *pcVar18 == *pcVar28;
                                                              pcVar18 = pcVar18 + (uint)bVar42 * -2
                                                                                  + 1;
                                                              pcVar28 = pcVar28 + (uint)bVar42 * -2
                                                                                  + 1;
                                                            } while (bVar40);
                                                            if (bVar40) {
                                                              bVar10 = true;
                                                            }
                                                            else {
                                                              iVar33 = 6;
                                                              pcVar18 = pcVar14;
                                                              pcVar28 = "-text";
                                                              do {
                                                                if (iVar33 == 0) break;
                                                                iVar33 = iVar33 + -1;
                                                                bVar40 = *pcVar18 == *pcVar28;
                                                                pcVar18 = pcVar18 + (uint)bVar42 *
                                                                                    -2 + 1;
                                                                pcVar28 = pcVar28 + (uint)bVar42 *
                                                                                    -2 + 1;
                                                              } while (bVar40);
                                                              if (bVar40) {
                                                                bVar7 = true;
                                                              }
                                                              else {
                                                                iVar33 = 6;
                                                                pcVar18 = pcVar14;
                                                                pcVar28 = "-x509";
                                                                do {
                                                                  if (iVar33 == 0) break;
                                                                  iVar33 = iVar33 + -1;
                                                                  bVar40 = *pcVar18 == *pcVar28;
                                                                  pcVar18 = pcVar18 + (uint)bVar42 *
                                                                                      -2 + 1;
                                                                  pcVar28 = pcVar28 + (uint)bVar42 *
                                                                                      -2 + 1;
                                                                } while (bVar40);
                                                                if (bVar40) {
                                                                  bVar5 = true;
                                                                }
                                                                else {
                                                                  iVar33 = 0xd;
                                                                  pcVar18 = pcVar14;
                                                                  pcVar28 = "-asn1-kludge";
                                                                  do {
                                                                    if (iVar33 == 0) break;
                                                                    iVar33 = iVar33 + -1;
                                                                    bVar40 = *pcVar18 == *pcVar28;
                                                                    pcVar18 = pcVar18 + (uint)bVar42
                                                                                        * -2 + 1;
                                                                    pcVar28 = pcVar28 + (uint)bVar42
                                                                                        * -2 + 1;
                                                                  } while (bVar40);
                                                                  if (bVar40) {
                                                                    local_518 = 1;
                                                                  }
                                                                  else {
                                                                    iVar33 = 0x10;
                                                                    pcVar18 = pcVar14;
                                                                    pcVar28 = "-no-asn1-kludge";
                                                                    do {
                                                                      if (iVar33 == 0) break;
                                                                      iVar33 = iVar33 + -1;
                                                                      bVar40 = *pcVar18 == *pcVar28;
                                                                      pcVar18 = pcVar18 + (uint)
                                                  bVar42 * -2 + 1;
                                                  pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                  } while (bVar40);
                                                  if (bVar40) {
                                                    local_518 = 0;
                                                  }
                                                  else {
                                                    iVar33 = 6;
                                                    pcVar18 = pcVar14;
                                                    pcVar28 = "-subj";
                                                    do {
                                                      if (iVar33 == 0) break;
                                                      iVar33 = iVar33 + -1;
                                                      bVar40 = *pcVar18 == *pcVar28;
                                                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                      pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                    } while (bVar40);
                                                    if (bVar40) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 == 0) goto LAB_0804e600;
                                                      local_538 = ppcVar37[1];
                                                      ppcVar39 = ppcVar37 + 1;
                                                    }
                                                    else {
                                                      iVar33 = 0x10;
                                                      pcVar18 = pcVar14;
                                                      pcVar28 = "-multivalue-rdn";
                                                      do {
                                                        if (iVar33 == 0) break;
                                                        iVar33 = iVar33 + -1;
                                                        bVar40 = *pcVar18 == *pcVar28;
                                                        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                        pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                      } while (bVar40);
                                                      if (!bVar40) {
                                                        iVar33 = 6;
                                                        pcVar18 = pcVar14;
                                                        pcVar28 = "-days";
                                                        do {
                                                          if (iVar33 == 0) break;
                                                          iVar33 = iVar33 + -1;
                                                          bVar40 = *pcVar18 == *pcVar28;
                                                          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                          pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                        } while (bVar40);
                                                        if (bVar40) {
                                                          param_1 = param_1 + -1;
                                                          if (param_1 != 0) {
                                                            ppcVar39 = ppcVar37 + 1;
                                                            lVar19 = strtol(ppcVar37[1],(char **)0x0
                                                                            ,10);
                                                            local_4ec = 0x1e;
                                                            if (lVar19 != 0) {
                                                              local_4ec = lVar19;
                                                            }
                                                            goto LAB_0804e11e;
                                                          }
                                                        }
                                                        else {
                                                          iVar33 = 0xc;
                                                          pcVar18 = pcVar14;
                                                          pcVar28 = "-set_serial";
                                                          do {
                                                            if (iVar33 == 0) break;
                                                            iVar33 = iVar33 + -1;
                                                            bVar40 = *pcVar18 == *pcVar28;
                                                            pcVar18 = pcVar18 + (uint)bVar42 * -2 +
                                                                                1;
                                                            pcVar28 = pcVar28 + (uint)bVar42 * -2 +
                                                                                1;
                                                          } while (bVar40);
                                                          if (bVar40) {
                                                            if (param_1 != 1) {
                                                              local_54c = s2i_ASN1_INTEGER((
                                                  X509V3_EXT_METHOD *)0x0,ppcVar37[1]);
                                                  pAVar32 = local_54c;
                                                  goto joined_r0x08050d84;
                                                  }
                                                  }
                                                  else {
                                                    iVar33 = 0xc;
                                                    pcVar18 = pcVar14;
                                                    pcVar28 = "-extensions";
                                                    do {
                                                      if (iVar33 == 0) break;
                                                      iVar33 = iVar33 + -1;
                                                      bVar40 = *pcVar18 == *pcVar28;
                                                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                      pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                    } while (bVar40);
                                                    if (!bVar40) {
                                                      iVar33 = 9;
                                                      pcVar18 = pcVar14;
                                                      pcVar28 = "-reqexts";
                                                      do {
                                                        if (iVar33 == 0) break;
                                                        iVar33 = iVar33 + -1;
                                                        bVar40 = *pcVar18 == *pcVar28;
                                                        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                        pcVar28 = pcVar28 + (uint)bVar42 * -2 + 1;
                                                      } while (bVar40);
                                                      if (bVar40) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 == 0) goto LAB_0804e600;
                                                        local_528 = (FILE *)ppcVar37[1];
                                                        ppcVar39 = ppcVar37 + 1;
                                                      }
                                                      else {
                                                        local_508 = EVP_get_digestbyname
                                                                              (pcVar14 + 1);
                                                        local_4f0 = (FILE *)local_508;
                                                        if (local_508 == (EVP_MD *)0x0) {
                                                          BIO_printf(bio_err,"unknown option %s\n",
                                                                     *ppcVar37);
                                                          goto LAB_0804e600;
                                                        }
                                                      }
                                                      goto LAB_0804e11e;
                                                    }
                                                    param_1 = param_1 + -1;
                                                    if (param_1 != 0) {
                                                      local_530 = ppcVar37[1];
                                                      ppcVar39 = ppcVar37 + 1;
                                                      goto LAB_0804e11e;
                                                    }
                                                  }
                                                  }
                                                  goto LAB_0804e600;
                                                  }
                                                  local_4f8 = 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_0804e11e;
                                                  }
                                                  if (param_1 != 1) {
                                                    pAVar32 = (ASN1_INTEGER *)
                                                              set_cert_ex(&local_4c0,ppcVar37[1]);
                                                    goto joined_r0x08050d84;
                                                  }
                                                  }
                                                  goto LAB_0804e600;
                                                  }
                                                  local_534 = 0x1000;
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                        goto LAB_0804e11e;
                                      }
                                      if ((param_1 != 1) &&
                                         ((local_550 != (_STACK *)0x0 ||
                                          (local_550 = sk_new_null(), local_550 != (_STACK *)0x0))))
                                      {
                                        pAVar32 = (ASN1_INTEGER *)sk_push(local_550,ppcVar37[1]);
                                        goto joined_r0x08050d84;
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
                  goto LAB_0804e600;
                }
                bVar41 = true;
              }
            }
          }
        }
LAB_0804e11e:
        param_1 = param_1 + -1;
        bVar40 = param_1 == 0;
        ppcVar37 = ppcVar39 + 1;
        if (bVar40) break;
        goto LAB_0804e126;
      }
      if (param_1 == 1) goto LAB_0804e600;
      local_56c = str2fmt(ppcVar37[1]);
      param_1 = param_1 + -2;
      bVar40 = param_1 == 0;
      ppcVar37 = ppcVar37 + 2;
    } while (!bVar40);
  }
  ERR_load_crypto_strings();
  iVar33 = app_passwd(bio_err,local_558,local_554,&local_4ac,&local_4a8);
  if (iVar33 == 0) {
    pcVar14 = "Error getting passwords\n";
LAB_0804e8df:
    BIO_printf(bio_err,pcVar14);
LAB_0804e8ed:
    pBVar15 = (BIO *)0x0;
    local_560 = (BIO *)0x0;
LAB_0804e8f7:
    pEVar38 = (EVP_PKEY *)0x0;
LAB_0804e8f9:
    x = (X509_REQ *)0x0;
    x_00 = (X509 *)0x0;
  }
  else {
    if (local_53c != (char *)0x0) {
      local_4a0.flags = -1;
      if (bVar4) {
        BIO_printf(bio_err,"Using configuration from %s\n",local_53c);
      }
      req_conf = NCONF_new((CONF_METHOD *)0x0);
      iVar33 = NCONF_load(req_conf,local_53c,&local_4a0.flags);
      if (iVar33 != 0) goto LAB_0804e1fa;
      pcVar14 = "error on line %ld of %s\n";
      goto LAB_0804e8df;
    }
    req_conf = config;
    if (config == (CONF *)0x0) {
      BIO_printf(bio_err,"Unable to load config info from %s\n",default_config_file);
      if (!bVar41) goto LAB_0804e1fa;
      goto LAB_0804e8ed;
    }
    if (bVar4) {
      BIO_printf(bio_err,"Using configuration from %s\n",default_config_file);
LAB_0804e1fa:
      if (req_conf != (CONF *)0x0) goto LAB_0804e203;
    }
    else {
LAB_0804e203:
      iVar33 = load_config(bio_err,req_conf);
      if (iVar33 == 0) goto LAB_0804e8ed;
      pcVar14 = NCONF_get_string(req_conf,(char *)0x0,"oid_file");
      if (pcVar14 == (char *)0x0) {
        ERR_clear_error();
      }
      else {
        pBVar15 = BIO_new_file(pcVar14,"r");
        if (pBVar15 != (BIO *)0x0) {
          OBJ_create_objects(pBVar15);
          BIO_free(pBVar15);
        }
      }
    }
    iVar33 = add_oid_section(bio_err,req_conf);
    if (iVar33 == 0) goto LAB_0804e8ed;
    pEVar30 = local_508;
    if (local_4f0 == (FILE *)0x0) {
      pcVar14 = NCONF_get_string(req_conf,"req","default_md");
      if (pcVar14 == (char *)0x0) {
        ERR_clear_error();
      }
      else {
        pEVar30 = EVP_get_digestbyname(pcVar14);
        if (pEVar30 == (EVP_MD *)0x0) {
          pEVar30 = local_508;
        }
      }
    }
    local_508 = pEVar30;
    if ((local_530 == (char *)0x0) &&
       (local_530 = NCONF_get_string(req_conf,"req","x509_extensions"), local_530 == (char *)0x0)) {
      ERR_clear_error();
    }
    else {
      X509V3_set_ctx(&local_4a0,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,(X509_CRL *)0x0,1);
      X509V3_set_nconf(&local_4a0,req_conf);
      iVar33 = X509V3_EXT_add_nconf(req_conf,&local_4a0,local_530,(X509 *)0x0);
      if (iVar33 == 0) {
        pcVar14 = "Error Loading extension section %s\n";
        goto LAB_0804e8df;
      }
    }
    if ((local_4ac == (char *)0x0) &&
       (local_4ac = NCONF_get_string(req_conf,"req","input_password"), local_4ac == (char *)0x0)) {
      ERR_clear_error();
    }
    if ((local_4a8 == (FILE *)0x0) &&
       (local_4a8 = (FILE *)NCONF_get_string(req_conf,"req","output_password"),
       local_4a8 == (FILE *)0x0)) {
      ERR_clear_error();
    }
    pcVar14 = NCONF_get_string(req_conf,"req","string_mask");
    if (pcVar14 == (char *)0x0) {
      ERR_clear_error();
    }
    else {
      iVar33 = ASN1_STRING_set_default_mask_asc(pcVar14);
      if (iVar33 == 0) {
        pcVar14 = "Invalid global string mask setting %s\n";
        goto LAB_0804e8df;
      }
    }
    if (local_534 == 0x1000) {
LAB_0804e388:
      local_534 = 0x1000;
    }
    else {
      pcVar14 = NCONF_get_string(req_conf,"req","utf8");
      if (pcVar14 == (char *)0x0) {
        ERR_clear_error();
      }
      else if ((((*pcVar14 == 'y') && (pcVar14[1] == 'e')) && (pcVar14[2] == 's')) &&
              (pcVar14[3] == '\0')) goto LAB_0804e388;
    }
    if ((local_528 == (FILE *)0x0) &&
       (local_528 = (FILE *)NCONF_get_string(req_conf,"req","req_extensions"),
       local_528 == (FILE *)0x0)) {
      ERR_clear_error();
    }
    else {
      X509V3_set_ctx(&local_4a0,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,(X509_CRL *)0x0,1);
      X509V3_set_nconf(&local_4a0,req_conf);
      iVar33 = X509V3_EXT_add_nconf(req_conf,&local_4a0,(char *)local_528,(X509 *)0x0);
      if (iVar33 == 0) {
        pcVar14 = "Error Loading request extension section %s\n";
        goto LAB_0804e8df;
      }
    }
    pBVar16 = BIO_s_file();
    local_560 = BIO_new(pBVar16);
    pBVar16 = BIO_s_file();
    pBVar15 = BIO_new(pBVar16);
    bVar40 = local_560 == (BIO *)0x0 || pBVar15 == (BIO *)0x0;
    if (bVar40) goto LAB_0804e8f7;
    pcVar14 = (char *)0x0;
    uVar17 = setup_engine(bio_err,local_568,0);
    if (local_548 != (char *)0x0) {
      local_4b8 = (EVP_PKEY *)load_key(bio_err,local_548,local_4e4,0,local_4ac,uVar17,"Private Key")
      ;
      if (local_4b8 == (EVP_PKEY *)0x0) goto LAB_0804e8f7;
      pcVar18 = NCONF_get_string(req_conf,"req","RANDFILE");
      if (pcVar18 == (char *)0x0) {
        ERR_clear_error();
      }
      pcVar14 = (char *)0x0;
      app_RAND_load_file(pcVar18,bio_err,0);
    }
    if ((local_4b8 == (EVP_PKEY *)0x0) && (bVar41)) {
      pcVar14 = NCONF_get_string(req_conf,"req","RANDFILE");
      if (pcVar14 == (char *)0x0) {
        ERR_clear_error();
      }
      app_RAND_load_file(pcVar14,bio_err,0);
      if (local_4d8 != (char *)0x0) {
        app_RAND_load_files(local_4d8);
      }
      iVar33 = NCONF_get_number_e(req_conf,"req","default_bits",&local_4b0);
      if (iVar33 != 0) {
        if (local_504 != (_STACK *)0x0) goto LAB_0804ef4f;
        if ((0x17f < local_4b0) || ((local_4b4 != 0x74 && (local_4b4 != 6)))) goto LAB_0804efff;
        pEVar38 = (EVP_PKEY *)0x0;
LAB_0804f060:
        x = (X509_REQ *)0x0;
        x_00 = (X509 *)0x0;
        BIO_printf(bio_err,"private key length is too short,\n");
        BIO_printf(bio_err,"it needs to be at least %d bits, not %ld\n",0x180,local_4b0);
        goto LAB_0804e8fd;
      }
      local_4b0 = 0x200;
      if (local_504 == (_STACK *)0x0) {
LAB_0804efff:
        pEVar38 = (EVP_PKEY *)set_keygen_ctx(&local_4b0,&local_4bc,local_564);
        if (pEVar38 != (EVP_PKEY *)0x0) goto LAB_0804efaa;
      }
      else {
LAB_0804ef4f:
        pEVar38 = (EVP_PKEY *)set_keygen_ctx(&local_4b0,&local_4bc,local_564);
        if (pEVar38 != (EVP_PKEY *)0x0) {
          if ((local_4b0 < 0x180) && ((local_4b4 == 0x74 || (local_4b4 == 6)))) goto LAB_0804f060;
LAB_0804efaa:
          if (local_55c != (_STACK *)0x0) {
            for (iVar33 = 0; iVar25 = sk_num(local_55c), iVar33 < iVar25; iVar33 = iVar33 + 1) {
              pvVar24 = sk_value(local_55c,iVar33);
              iVar25 = pkey_ctrl_string(pEVar38,pvVar24);
              if (iVar25 < 1) {
                x = (X509_REQ *)0x0;
                BIO_printf(bio_err,"parameter error \"%s\"\n",pvVar24);
                x_00 = (X509 *)0x0;
                ERR_print_errors(bio_err);
                goto LAB_0804e8fd;
              }
            }
          }
          BIO_printf(bio_err,"Generating a %ld bit %s private key\n",local_4b0,local_4bc);
          EVP_PKEY_CTX_set_cb((EVP_PKEY_CTX *)pEVar38,genpkey_cb);
          EVP_PKEY_CTX_set_app_data((EVP_PKEY_CTX *)pEVar38,bio_err);
          iVar33 = EVP_PKEY_keygen((EVP_PKEY_CTX *)pEVar38,&local_4b8);
          if (iVar33 < 1) {
            x = (X509_REQ *)0x0;
            x_00 = (X509 *)0x0;
            BIO_puts(bio_err,"Error Generating Key\n");
            goto LAB_0804e8fd;
          }
          EVP_PKEY_CTX_free((EVP_PKEY_CTX *)pEVar38);
          app_RAND_write_file(pcVar14,bio_err);
          if ((local_514 == (char *)0x0) &&
             (local_514 = NCONF_get_string(req_conf,"req","default_keyfile"),
             local_514 == (char *)0x0)) {
            ERR_clear_error();
            BIO_printf(bio_err,"writing new private key to stdout\n");
            BIO_ctrl(pBVar15,0x6a,0,stdout);
          }
          else {
            BIO_printf(bio_err,"writing new private key to \'%s\'\n",local_514);
            lVar19 = BIO_ctrl(pBVar15,0x6c,5,local_514);
            local_4fc = local_514;
            if (lVar19 < 1) goto LAB_080504ea;
          }
          pcVar14 = NCONF_get_string(req_conf,"req","encrypt_rsa_key");
          local_50c = pEVar13;
          if (pcVar14 == (char *)0x0) {
            ERR_clear_error();
            pcVar14 = NCONF_get_string(req_conf,"req","encrypt_key");
            if (pcVar14 != (char *)0x0) goto LAB_08050661;
            ERR_clear_error();
          }
          else {
LAB_08050661:
            if (((*pcVar14 == 'n') && (pcVar14[1] == 'o')) &&
               (local_50c = (EVP_CIPHER *)0x0, pcVar14[2] != '\0')) {
              local_50c = pEVar13;
            }
          }
          pEVar13 = (EVP_CIPHER *)0x0;
          if (!bVar12) {
            pEVar13 = local_50c;
          }
          iVar33 = 0;
          while (pcVar14 = (char *)local_4a8,
                iVar25 = PEM_write_bio_PrivateKey
                                   (pBVar15,local_4b8,pEVar13,(uchar *)0x0,0,(undefined1 *)0x0,
                                    local_4a8), iVar25 == 0) {
            uVar29 = ERR_peek_error();
            if (((uVar29 & 0xfff) != 0x6d) || (iVar33 == 3)) goto LAB_0804e8f7;
            ERR_clear_error();
            iVar33 = iVar33 + 1;
          }
          x = (X509_REQ *)0x0;
          BIO_printf(bio_err,"-----\n");
          goto LAB_0804f12f;
        }
      }
      goto LAB_0804e8f9;
    }
    if (!bVar41) {
      if (local_4fc == (char *)0x0) {
        pcVar14 = (char *)0x0;
        BIO_ctrl(local_560,0x6a,0,stdin);
      }
      else {
        pcVar14 = (char *)0x3;
        lVar19 = BIO_ctrl(local_560,0x6c,3,local_4fc);
        if (lVar19 < 1) {
LAB_080504ea:
          perror(local_4fc);
          pEVar38 = (EVP_PKEY *)0x0;
          x = (X509_REQ *)0x0;
          x_00 = (X509 *)0x0;
          goto LAB_0804e8fd;
        }
      }
      if (local_570 == 1) {
        x = d2i_X509_REQ_bio(local_560,(X509_REQ **)0x0);
      }
      else {
        if (local_570 != 3) {
          pEVar38 = (EVP_PKEY *)0x0;
          x = (X509_REQ *)0x0;
          x_00 = (X509 *)0x0;
          BIO_printf(bio_err,"bad input format specified for X509 request\n");
          goto LAB_0804e8fd;
        }
        pcVar14 = (char *)0x0;
        x = PEM_read_bio_X509_REQ(local_560,(X509_REQ **)0x0,(undefined1 *)0x0,(void *)0x0);
      }
      local_518 = -1;
      if (x != (X509_REQ *)0x0) goto LAB_0804f12f;
      pcVar18 = "unable to load X509 request\n";
      goto LAB_0804f713;
    }
    x = (X509_REQ *)0x0;
LAB_0804f12f:
    if (!(bool)(bVar41 | bVar5)) {
LAB_0804f211:
      bVar12 = !bVar5;
      bVar41 = local_538 != (char *)0x0 && bVar12;
      if (local_538 != (char *)0x0 && bVar12) {
        bVar12 = bVar41;
        if (bVar4) {
          BIO_printf(bio_err,"Modifying Request\'s Subject\n");
          print_name(bio_err,"old subject=",x->req_info->subject,local_4c4);
          iVar33 = build_subject(local_4f8);
          if (iVar33 == 0) goto LAB_08050347;
          pXVar2 = x->req_info;
          (pXVar2->enc).modified = 1;
          print_name(bio_err,"new subject=",pXVar2->subject,local_4c4);
        }
        else {
          iVar33 = build_subject(local_4f8);
          if (iVar33 == 0) {
LAB_08050347:
            pcVar18 = "ERROR: cannot modify subject\n";
            goto LAB_0804f713;
          }
          (x->req_info->enc).modified = 1;
        }
      }
      if ((bool)(bVar3 & bVar12)) {
        if (local_4b8 == (EVP_PKEY *)0x0) {
          local_4b8 = X509_REQ_get_pubkey(x);
          if (local_4b8 == (EVP_PKEY *)0x0) goto LAB_080502d3;
          iVar33 = X509_REQ_verify(x,local_4b8);
          EVP_PKEY_free(local_4b8);
          local_4b8 = (EVP_PKEY *)0x0;
        }
        else {
          iVar33 = X509_REQ_verify(x,local_4b8);
        }
        if (iVar33 < 0) goto LAB_080502d3;
        if (iVar33 == 0) {
          x_00 = (X509 *)0x0;
          BIO_printf(bio_err,"verify failure\n");
          ERR_print_errors(bio_err);
        }
        else {
          x_00 = (X509 *)0x0;
          BIO_printf(bio_err,"verify OK\n");
        }
      }
      else {
        bVar40 = false;
        x_00 = (X509 *)0x0;
      }
LAB_0804f2b6:
      if (((!bVar6) || (bVar7)) || ((bool)(bVar10 | bVar9 | bVar8))) {
        if (local_520 == (char *)0x0) {
          BIO_ctrl(pBVar15,0x6a,0,stdout);
        }
        else {
          if ((local_514 == (char *)0x0) || (iVar33 = strcmp(local_520,local_514), iVar33 != 0)) {
            iVar33 = BIO_ctrl(pBVar15,0x6c,5,local_520);
          }
          else {
            iVar33 = BIO_ctrl(pBVar15,0x6c,9,local_520);
          }
          if (iVar33 == 0) {
            pEVar38 = (EVP_PKEY *)0x0;
            perror(local_520);
            goto LAB_0804e8fd;
          }
        }
        if (bVar8) {
          pEVar38 = X509_REQ_get_pubkey(x);
          if (pEVar38 == (EVP_PKEY *)0x0) {
            BIO_printf(bio_err,"Error getting public key\n");
            ERR_print_errors(bio_err);
            goto LAB_0804e8fd;
          }
          PEM_write_bio_PUBKEY(pBVar15,pEVar38);
          EVP_PKEY_free(pEVar38);
        }
        if (bVar7) {
          if (bVar40) {
            X509_print_ex(pBVar15,x_00,local_4c4,local_4c0);
            if (bVar10) goto LAB_0804f36a;
            if (!bVar9) goto LAB_0804f402;
LAB_0804f392:
            pEVar38 = X509_get_pubkey(x_00);
          }
          else {
            X509_REQ_print_ex(pBVar15,x,local_4c4,local_4c0);
            if (bVar10) {
LAB_0804f540:
              print_name(pBVar15,"subject=",x->req_info->subject,local_4c4);
            }
            if (!bVar9) goto LAB_0804f402;
LAB_0804f566:
            pEVar38 = X509_REQ_get_pubkey(x);
          }
          if (pEVar38 == (EVP_PKEY *)0x0) {
            fwrite("Modulus=unavailable\n",1,0x14,stdout);
            goto LAB_0804e8fd;
          }
          fwrite("Modulus=",1,8,stdout);
          iVar33 = EVP_PKEY_base_id(pEVar38);
          if (iVar33 == 6) {
            BN_print(pBVar15,((pEVar38->pkey).rsa)->n);
          }
          else {
            fwrite("Wrong Algorithm type",1,0x14,stdout);
          }
          EVP_PKEY_free(pEVar38);
          fputc(10,stdout);
        }
        else if (bVar10) {
          if (!bVar40) goto LAB_0804f540;
LAB_0804f36a:
          uVar29 = local_4c4;
          pXVar20 = X509_get_subject_name(x_00);
          print_name(pBVar15,"subject=",pXVar20,uVar29);
          if (bVar9) goto LAB_0804f392;
        }
        else if (bVar9) {
          if (bVar40) goto LAB_0804f392;
          goto LAB_0804f566;
        }
LAB_0804f402:
        if (!(bool)(bVar5 | bVar6)) {
          if (local_56c == 1) {
            iVar33 = i2d_X509_REQ_bio(pBVar15,x);
LAB_0804f43a:
            if (iVar33 == 0) {
              pEVar38 = (EVP_PKEY *)0x0;
              BIO_printf(bio_err,"unable to write X509 request\n");
              goto LAB_0804e8fd;
            }
            goto LAB_0804f442;
          }
          if (local_56c == 3) {
            if (bVar11) {
              iVar33 = PEM_write_bio_X509_REQ_NEW(pBVar15,x);
            }
            else {
              iVar33 = PEM_write_bio_X509_REQ(pBVar15,x);
            }
            goto LAB_0804f43a;
          }
LAB_0804f463:
          pEVar38 = (EVP_PKEY *)0x0;
          BIO_printf(bio_err,"bad output format specified for outfile\n");
          goto LAB_0804e8fd;
        }
LAB_0804f442:
        if (((!bVar6) && (bVar40)) && (x_00 != (X509 *)0x0)) {
          if (local_56c == 1) {
            iVar33 = i2d_X509_bio(pBVar15,x_00);
          }
          else {
            if (local_56c != 3) goto LAB_0804f463;
            iVar33 = PEM_write_bio_X509(pBVar15,x_00);
          }
          if (iVar33 == 0) {
            BIO_printf(bio_err,"unable to write X509 certificate\n");
            goto LAB_0804f189;
          }
        }
      }
      pEVar38 = (EVP_PKEY *)0x0;
      local_570 = 0;
      goto LAB_0804e916;
    }
    if (local_4b8 == (EVP_PKEY *)0x0) {
      pcVar18 = "you need to specify a private key\n";
    }
    else {
      if (x != (X509_REQ *)0x0) {
LAB_0804f154:
        if (!bVar5) {
          X509V3_set_ctx(&local_4a0,(X509 *)0x0,(X509 *)0x0,x,(X509_CRL *)0x0,0);
          X509V3_set_nconf(&local_4a0,req_conf);
          if ((local_528 == (FILE *)0x0) ||
             (pcVar14 = (char *)local_528,
             iVar33 = X509V3_EXT_REQ_add_nconf(req_conf,&local_4a0,(char *)local_528,x), iVar33 != 0
             )) {
            iVar33 = do_X509_REQ_sign(bio_err,x,local_4b8,local_508,local_550);
            if (iVar33 != 0) goto LAB_0804f211;
            ERR_print_errors(bio_err);
          }
          else {
            BIO_printf(bio_err,"Error Loading extension section %s\n",local_528);
          }
LAB_080502d3:
          pEVar38 = (EVP_PKEY *)0x0;
          x_00 = (X509 *)0x0;
          goto LAB_0804e8fd;
        }
        x_00 = X509_new();
        if ((x_00 != (X509 *)0x0) &&
           ((local_530 == (char *)0x0 || (iVar33 = X509_set_version(x_00,2), iVar33 != 0)))) {
          if (local_54c == (ASN1_INTEGER *)0x0) {
            pAVar32 = X509_get_serialNumber(x_00);
            iVar33 = rand_serial(0,pAVar32);
          }
          else {
            iVar33 = X509_set_serialNumber(x_00,local_54c);
          }
          if ((((((iVar33 != 0) &&
                 (iVar33 = X509_set_issuer_name(x_00,x->req_info->subject), iVar33 != 0)) &&
                (pAVar31 = X509_gmtime_adj(x_00->cert_info->validity->notBefore,0),
                pAVar31 != (ASN1_TIME *)0x0)) &&
               ((pAVar31 = X509_time_adj_ex(x_00->cert_info->validity->notAfter,local_4ec,0,
                                            (time_t *)0x0), pAVar31 != (ASN1_TIME *)0x0 &&
                (iVar33 = X509_set_subject_name(x_00,x->req_info->subject), iVar33 != 0)))) &&
              (pEVar38 = X509_REQ_get_pubkey(x), pEVar38 != (EVP_PKEY *)0x0)) &&
             (iVar33 = X509_set_pubkey(x_00,pEVar38), iVar33 != 0)) {
            EVP_PKEY_free(pEVar38);
            X509V3_set_ctx(&local_4a0,x_00,x_00,(X509_REQ *)0x0,(X509_CRL *)0x0,0);
            X509V3_set_nconf(&local_4a0,req_conf);
            if ((local_530 == (char *)0x0) ||
               (iVar33 = X509V3_EXT_add_nconf(req_conf,&local_4a0,local_530,x_00), iVar33 != 0)) {
              iVar33 = do_X509_sign(bio_err,x_00,local_4b8,local_508,local_550);
              if (iVar33 != 0) {
                if (local_538 != (char *)0x0) {
                  pEVar38 = (EVP_PKEY *)0x0;
                  BIO_printf(bio_err,"Cannot modifiy certificate subject\n");
                  goto LAB_0804e8fd;
                }
                bVar40 = true;
                goto LAB_0804f2b6;
              }
              ERR_print_errors(bio_err);
            }
            else {
              BIO_printf(bio_err,"Error Loading extension section %s\n",local_530);
            }
          }
        }
LAB_0804f189:
        pEVar38 = (EVP_PKEY *)0x0;
        goto LAB_0804e8fd;
      }
      x = X509_REQ_new();
      pEVar38 = local_4b8;
      if (x == (X509_REQ *)0x0) goto LAB_080502d3;
      pbVar21 = (byte *)NCONF_get_string(req_conf,"req","prompt");
      if (pbVar21 == (byte *)0x0) {
        ERR_clear_error();
        bVar41 = false;
      }
      else {
        iVar33 = 0x6e - (uint)*pbVar21;
        if ((iVar33 == 0) && (iVar33 = 0x6f - (uint)pbVar21[1], iVar33 == 0)) {
          iVar33 = -(uint)pbVar21[2];
        }
        bVar41 = iVar33 == 0;
      }
      pFVar22 = (FILE *)NCONF_get_string(req_conf,"req","distinguished_name");
      if (pFVar22 == (FILE *)0x0) {
        pcVar14 = "distinguished_name";
        BIO_printf(bio_err,"unable to find \'%s\' in config\n","distinguished_name");
      }
      else {
        p_Var23 = (_STACK *)NCONF_get_section(req_conf,(char *)pFVar22);
        if (p_Var23 == (_STACK *)0x0) {
          BIO_printf(bio_err,"unable to get \'%s\' section\n",pFVar22);
          pcVar14 = (char *)pFVar22;
        }
        else {
          pcVar14 = "attributes";
          section = (FILE *)NCONF_get_string(req_conf,"req","attributes");
          if (section == (FILE *)0x0) {
            ERR_clear_error();
            local_504 = (_STACK *)0x0;
          }
          else {
            local_504 = (_STACK *)NCONF_get_section(req_conf,(char *)section);
            if (local_504 == (_STACK *)0x0) {
              BIO_printf(bio_err,"unable to get \'%s\' section\n",section);
              pcVar14 = (char *)section;
              goto LAB_0804f6d6;
            }
          }
          iVar33 = X509_REQ_set_version(x,0);
          if (iVar33 != 0) {
            if (bVar41) {
              pXVar20 = x->req_info->subject;
              for (iVar33 = 0; iVar25 = sk_num(p_Var23), iVar33 < iVar25; iVar33 = iVar33 + 1) {
                pvVar24 = sk_value(p_Var23,iVar33);
                pbVar21 = *(byte **)((int)pvVar24 + 4);
                bVar42 = *pbVar21;
                pbVar34 = pbVar21;
                while (bVar42 != 0) {
                  if (((bVar42 & 0xfd) == 0x2c) || (bVar42 == 0x3a)) {
                    bVar42 = pbVar34[1];
                    if (bVar42 != 0) {
                      pbVar21 = pbVar34 + 1;
                    }
                    break;
                  }
                  pbVar34 = pbVar34 + 1;
                  bVar42 = *pbVar34;
                }
                pcVar14 = (char *)-(uint)(bVar42 == 0x2b);
                iVar25 = X509_NAME_add_entry_by_txt
                                   (pXVar20,(char *)pbVar21,local_534,*(uchar **)((int)pvVar24 + 8),
                                    -1,-1,(int)pcVar14);
                if (iVar25 == 0) goto LAB_0804f6d6;
              }
              iVar33 = X509_NAME_entry_count(pXVar20);
              if (iVar33 == 0) {
LAB_0804fe4c:
                BIO_printf(bio_err,"error, no objects specified in config file\n");
              }
              else {
                if (!bVar5) {
                  for (iVar33 = 0; iVar25 = sk_num(local_504), iVar33 < iVar25; iVar33 = iVar33 + 1)
                  {
                    pvVar24 = sk_value(local_504,iVar33);
                    iVar25 = X509_REQ_add1_attr_by_txt
                                       (x,*(char **)((int)pvVar24 + 4),local_534,
                                        *(uchar **)((int)pvVar24 + 8),-1);
                    if (iVar25 == 0) goto LAB_0804f6d6;
                  }
                }
LAB_0804f7ab:
                iVar33 = X509_REQ_set_pubkey(x,pEVar38);
                if (iVar33 != 0) {
                  if ((0 < local_518) &&
                     (iVar33 = sk_num((_STACK *)x->req_info->attributes), iVar33 == 0)) {
                    sk_free((_STACK *)x->req_info->attributes);
                    x->req_info->attributes = (stack_st_X509_ATTRIBUTE *)0x0;
                  }
                  local_538 = (char *)0x0;
                  goto LAB_0804f154;
                }
              }
            }
            else if (local_538 == (char *)0x0) {
              pXVar20 = x->req_info->subject;
              if (batch == 0) {
                BIO_printf(bio_err,
                           "You are about to be asked to enter information that will be incorporated\n"
                          );
                BIO_printf(bio_err,"into your certificate request.\n");
                BIO_printf(bio_err,
                           "What you are about to enter is what is called a Distinguished Name or a DN.\n"
                          );
                BIO_printf(bio_err,"There are quite a few fields but you can leave some blank\n");
                BIO_printf(bio_err,"For some fields there will be a default value,\n");
                BIO_printf(bio_err,"If you enter \'.\', the field will be left blank.\n");
                BIO_printf(bio_err,"-----\n");
              }
              iVar33 = sk_num(p_Var23);
              if (iVar33 != 0) {
                local_4fc = (char *)0xffffffff;
LAB_0804f8d4:
                do {
                  local_4fc = (char *)((int)local_4fc + 1);
                  iVar33 = sk_num(p_Var23);
                  if (iVar33 <= (int)local_4fc) {
                    iVar33 = X509_NAME_entry_count(pXVar20);
                    if (iVar33 == 0) goto LAB_0804fe4c;
                    if ((bVar5) || (local_504 == (_STACK *)0x0)) goto LAB_0804f7ab;
                    iVar33 = sk_num(local_504);
                    if ((0 < iVar33) && (batch == 0)) {
                      BIO_printf(bio_err,"\nPlease enter the following \'extra\' attributes\n");
                      BIO_printf(bio_err,"to be sent with your certificate request\n");
                    }
                    local_538 = (char *)0x0;
                    goto LAB_0804fef6;
                  }
                  pvVar24 = sk_value(p_Var23,(int)local_4fc);
                  pbVar21 = *(byte **)((int)pvVar24 + 4);
                  iVar33 = check_end();
                  if ((iVar33 != 0) &&
                     (((iVar33 = check_end(), iVar33 != 0 && (iVar33 = check_end(), iVar33 != 0)) &&
                      (iVar33 = check_end(), iVar33 != 0)))) {
                    bVar42 = *pbVar21;
                    pbVar34 = pbVar21;
                    bVar1 = bVar42;
                    if (bVar42 == 0) {
                      local_4f0 = (FILE *)0x0;
                    }
                    else {
                      do {
                        if (((bVar1 & 0xfd) == 0x2c) || (bVar1 == 0x3a)) {
                          if (pbVar34[1] != 0) {
                            pbVar21 = pbVar34 + 1;
                            bVar42 = pbVar34[1];
                          }
                          break;
                        }
                        pbVar34 = pbVar34 + 1;
                        bVar1 = *pbVar34;
                      } while (bVar1 != 0);
                      local_4f0 = (FILE *)0x0;
                      if (bVar42 == 0x2b) {
                        pbVar21 = pbVar21 + 1;
                        local_4f0 = (FILE *)0xffffffff;
                      }
                    }
                    iVar33 = OBJ_txt2nid((char *)pbVar21);
                    if (iVar33 != 0) {
                      iVar25 = BIO_snprintf(local_484,100,"%s_default",
                                            *(undefined4 *)((int)pvVar24 + 4));
                      if (iVar25 < 100) {
                        pcVar18 = NCONF_get_string(req_conf,(char *)pFVar22,local_484);
                        if (pcVar18 == (char *)0x0) {
                          pcVar18 = "";
                          ERR_clear_error();
                        }
                        BIO_snprintf(local_484,100,"%s_value",*(undefined4 *)((int)pvVar24 + 4));
                        src = (FILE *)NCONF_get_string(req_conf,(char *)pFVar22,local_484);
                        if (src == (FILE *)0x0) {
                          ERR_clear_error();
                        }
                        BIO_snprintf(local_484,100,"%s_min",*(undefined4 *)((int)pvVar24 + 4));
                        iVar25 = NCONF_get_number_e(req_conf,(char *)pFVar22,local_484,&local_4a4);
                        if (iVar25 == 0) {
                          ERR_clear_error();
                          local_4a4 = -1;
                        }
                        BIO_snprintf(local_484,100,"%s_max",*(undefined4 *)((int)pvVar24 + 4));
                        iVar25 = NCONF_get_number_e(req_conf,(char *)pFVar22,local_484,
                                                    &local_4a0.flags);
                        if (iVar25 == 0) {
                          ERR_clear_error();
                          local_4a0.flags = -1;
                        }
                        uVar17 = *(undefined4 *)((int)pvVar24 + 8);
                        do {
                          if (batch == 0) {
                            BIO_printf(bio_err,"%s [%s]:",uVar17,pcVar18);
                          }
                          pcVar14 = (char *)0x0;
                          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
                          if (src == (FILE *)0x0) {
                            local_420 = '\0';
                            if (batch == 0) {
                              pcVar14 = (char *)stdin;
                              pcVar28 = fgets(&local_420,0x400,stdin);
                              if (pcVar28 != (char *)0x0) goto LAB_0804fb6c;
                              goto LAB_0804f6d6;
                            }
                            local_420 = '\n';
                            cStack_41f = '\0';
LAB_0804fd4e:
                            if (*pcVar18 == '\0') goto LAB_0804f8d4;
                            BUF_strlcpy(&local_420,pcVar18,0x400);
                            pcVar14 = (char *)0x400;
                            BUF_strlcat(&local_420,"\n",0x400);
                            puVar27 = (uint *)&local_420;
                          }
                          else {
                            BUF_strlcpy(&local_420,(char *)src,0x400);
                            BUF_strlcat(&local_420,"\n",0x400);
                            pcVar14 = (char *)src;
                            BIO_printf(bio_err,"%s\n",src);
LAB_0804fb6c:
                            if (local_420 == '\0') goto LAB_0804f6d6;
                            if (local_420 == '\n') goto LAB_0804fd4e;
                            puVar27 = (uint *)&local_420;
                            if ((local_420 == '.') && (cStack_41f == '\n')) goto LAB_0804f8d4;
                          }
                          do {
                            puVar26 = puVar27;
                            uVar35 = *puVar26 + 0xfefefeff & ~*puVar26;
                            uVar36 = uVar35 & 0x80808080;
                            puVar27 = puVar26 + 1;
                          } while (uVar36 == 0);
                          bVar41 = (uVar35 & 0x8080) == 0;
                          if (bVar41) {
                            uVar36 = uVar36 >> 0x10;
                          }
                          if (bVar41) {
                            puVar27 = (uint *)((int)puVar26 + 6);
                          }
                          iVar25 = -(int)&local_420 - (uint)CARRY1((byte)uVar36,(byte)uVar36);
                          if (*(uchar *)((int)puVar27 + (int)(auStack_424 + iVar25)) != '\n')
                          goto LAB_0804fd81;
                          *(uchar *)((int)puVar27 + (int)(auStack_424 + iVar25)) = '\0';
                          iVar25 = req_check_len();
                          if (iVar25 != 0) goto LAB_0804fcd8;
                          if ((batch != 0) || (src != (FILE *)0x0)) goto LAB_0804f6d6;
                        } while( true );
                      }
                      goto LAB_0804fdb3;
                    }
                  }
                } while( true );
              }
              BIO_printf(bio_err,"No template, please set one up.\n");
            }
            else {
              iVar33 = build_subject(local_4f8);
              if (iVar33 != 0) goto LAB_0804f7ab;
            }
          }
        }
      }
LAB_0804f6d6:
      if ((0 < local_518) && (iVar33 = sk_num((_STACK *)x->req_info->attributes), iVar33 == 0)) {
        sk_free((_STACK *)x->req_info->attributes);
        x->req_info->attributes = (stack_st_X509_ATTRIBUTE *)0x0;
      }
      pcVar18 = "problems making Certificate Request\n";
    }
LAB_0804f713:
    pEVar38 = (EVP_PKEY *)0x0;
    x_00 = (X509 *)0x0;
    BIO_printf(bio_err,pcVar18,pcVar14);
  }
LAB_0804e8fd:
  ERR_print_errors(bio_err);
  local_570 = 1;
LAB_0804e916:
  if ((req_conf != (CONF *)0x0) && (req_conf != config)) {
    NCONF_free(req_conf);
  }
  BIO_free(local_560);
  BIO_free_all(pBVar15);
  EVP_PKEY_free(local_4b8);
  if (pEVar38 != (EVP_PKEY *)0x0) {
    EVP_PKEY_CTX_free((EVP_PKEY_CTX *)pEVar38);
  }
  if (local_55c != (_STACK *)0x0) {
    sk_free(local_55c);
  }
  if (local_550 != (_STACK *)0x0) {
    sk_free(local_550);
  }
  if (local_564 != (ENGINE *)0x0) {
    ENGINE_free(local_564);
  }
  if (local_4bc != (void *)0x0) {
    CRYPTO_free(local_4bc);
  }
  X509_REQ_free(x);
  X509_free(x_00);
  ASN1_INTEGER_free(local_54c);
  if ((local_558 != (char *)0x0) && (local_4ac != (char *)0x0)) {
    CRYPTO_free(local_4ac);
  }
  if ((local_554 != (char *)0x0) && (local_4a8 != (FILE *)0x0)) {
    CRYPTO_free(local_4a8);
  }
  OBJ_cleanup();
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_570;
LAB_0804fef6:
  iVar33 = sk_num(local_504);
  if ((int)local_538 < iVar33) {
    pvVar24 = sk_value(local_504,(int)local_538);
    pcVar18 = *(char **)((int)pvVar24 + 4);
    iVar33 = OBJ_txt2nid(pcVar18);
    if (iVar33 == 0) goto LAB_0804ff3c;
    iVar25 = BIO_snprintf(local_484,100,"%s_default",pcVar18);
    if (iVar25 < 100) {
      pcVar28 = NCONF_get_string(req_conf,(char *)section,local_484);
      if (pcVar28 == (char *)0x0) {
        pcVar28 = "";
        ERR_clear_error();
      }
      BIO_snprintf(local_484,100,"%s_value",pcVar18);
      pFVar22 = (FILE *)NCONF_get_string(req_conf,(char *)section,local_484);
      if (pFVar22 == (FILE *)0x0) {
        ERR_clear_error();
      }
      BIO_snprintf(local_484,100,"%s_min",pcVar18);
      iVar25 = NCONF_get_number_e(req_conf,(char *)section,local_484,&local_4a4);
      if (iVar25 == 0) {
        ERR_clear_error();
        local_4a4 = -1;
      }
      BIO_snprintf(local_484,100,"%s_max",pcVar18);
      iVar25 = NCONF_get_number_e(req_conf,(char *)section,local_484,&local_4a0.flags);
      if (iVar25 == 0) {
        ERR_clear_error();
        local_4a0.flags = -1;
      }
      uVar17 = *(undefined4 *)((int)pvVar24 + 8);
      do {
        if (batch == 0) {
          BIO_printf(bio_err,"%s [%s]:",uVar17,pcVar28);
        }
        pcVar14 = (char *)0x0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        if (pFVar22 == (FILE *)0x0) {
          buf_16750[0] = '\0';
          if (batch == 0) {
            pcVar14 = (char *)stdin;
            pcVar18 = fgets(buf_16750,0x400,stdin);
            if (pcVar18 != (char *)0x0) goto LAB_080500d9;
            goto LAB_0804f6d6;
          }
          buf_16750[0] = '\n';
          buf_16750[1] = '\0';
LAB_08050217:
          if (*pcVar28 == '\0') goto LAB_0804ff3c;
          BUF_strlcpy(buf_16750,pcVar28,0x400);
          pcVar14 = (char *)0x400;
          BUF_strlcat(buf_16750,"\n",0x400);
        }
        else {
          BUF_strlcpy(buf_16750,(char *)pFVar22,0x400);
          BUF_strlcat(buf_16750,"\n",0x400);
          pcVar14 = (char *)pFVar22;
          BIO_printf(bio_err,"%s\n",pFVar22);
LAB_080500d9:
          if (buf_16750[0] == '\0') goto LAB_0804f6d6;
          if (buf_16750[0] == '\n') goto LAB_08050217;
          if ((buf_16750[0] == '.') && (buf_16750[1] == '\n')) goto LAB_0804ff3c;
        }
        puVar27 = (uint *)buf_16750;
        do {
          puVar26 = puVar27;
          uVar35 = *puVar26 + 0xfefefeff & ~*puVar26;
          uVar36 = uVar35 & 0x80808080;
          puVar27 = puVar26 + 1;
        } while (uVar36 == 0);
        bVar41 = (uVar35 & 0x8080) == 0;
        if (bVar41) {
          uVar36 = uVar36 >> 0x10;
        }
        if (bVar41) {
          puVar27 = (uint *)((int)puVar26 + 6);
        }
        iVar25 = (int)puVar27 + (-0x82fd8e4 - (uint)CARRY1((byte)uVar36,(byte)uVar36));
        if (buf_16750[iVar25] != '\n') goto LAB_0804fd81;
        buf_16750[iVar25] = 0;
        iVar25 = req_check_len();
        if (iVar25 != 0) goto LAB_0805018b;
        if ((batch != 0) || (pFVar22 != (FILE *)0x0)) goto LAB_0804f6d6;
      } while( true );
    }
LAB_0804fdb3:
    pcVar14 = *(char **)((int)pvVar24 + 4);
    BIO_printf(bio_err,"Name \'%s\' too long\n",pcVar14);
    goto LAB_0804f6d6;
  }
  goto LAB_0804f7ab;
LAB_0805018b:
  iVar33 = X509_REQ_add1_attr_by_NID(x,iVar33,local_534,buf_16750,-1);
  if (iVar33 == 0) {
    BIO_printf(bio_err,"Error adding attribute\n");
    ERR_print_errors(bio_err);
    goto LAB_0804f6d6;
  }
LAB_0804ff3c:
  local_538 = (char *)((int)local_538 + 1);
  goto LAB_0804fef6;
LAB_0804fd81:
  BIO_printf(bio_err,"weird input :-(\n",pcVar14);
  goto LAB_0804f6d6;
LAB_0804fcd8:
  iVar33 = X509_NAME_add_entry_by_NID
                     (pXVar20,iVar33,local_534,(uchar *)&local_420,-1,-1,(int)local_4f0);
  pcVar14 = (char *)local_4f0;
  if (iVar33 == 0) goto LAB_0804f6d6;
  goto LAB_0804f8d4;
}

