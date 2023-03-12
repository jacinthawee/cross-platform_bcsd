
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
  EVP_MD *pEVar21;
  ulong uVar22;
  ASN1_TIME *pAVar23;
  ASN1_INTEGER *pAVar24;
  byte *pbVar25;
  FILE *pFVar26;
  _STACK *p_Var27;
  FILE *section;
  void *pvVar28;
  int iVar29;
  FILE *src;
  uint *puVar30;
  uint *puVar31;
  char *pcVar32;
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
  int local_51c;
  char *local_518;
  char *local_514;
  EVP_CIPHER *local_50c;
  EVP_MD *local_508;
  _STACK *local_500;
  undefined4 local_4fc;
  EVP_MD *local_4f4;
  long local_4f0;
  FILE *local_4ec;
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
    local_4fc = 0;
    local_538 = (char *)0x0;
    local_554 = (char *)0x0;
    local_558 = (char *)0x0;
    local_4d8 = (char *)0x0;
    bVar8 = false;
    local_54c = (ASN1_INTEGER *)0x0;
    local_568 = (char *)0x0;
    local_514 = (char *)0x0;
    local_53c = (char *)0x0;
    local_548 = (char *)0x0;
    local_518 = (char *)0x0;
    local_500 = (_STACK *)0x0;
    bVar9 = false;
    bVar10 = false;
    bVar11 = false;
    local_51c = 0;
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
    local_4ec = (FILE *)0x0;
    local_4f0 = 0x1e;
    bVar5 = false;
    local_564 = (ENGINE *)0x0;
    local_508 = (EVP_MD *)0x0;
    local_528 = (FILE *)0x0;
    local_530 = (char *)0x0;
    local_4f4 = (EVP_MD *)0x0;
  }
  else {
    local_508 = (EVP_MD *)0x0;
    local_4f4 = (EVP_MD *)0x0;
    local_4fc = 0;
    local_538 = (char *)0x0;
    local_554 = (char *)0x0;
    local_558 = (char *)0x0;
    local_4d8 = (char *)0x0;
    bVar8 = false;
    local_54c = (ASN1_INTEGER *)0x0;
    local_528 = (FILE *)0x0;
    local_530 = (char *)0x0;
    local_568 = (char *)0x0;
    local_514 = (char *)0x0;
    local_53c = (char *)0x0;
    local_548 = (char *)0x0;
    local_518 = (char *)0x0;
    local_500 = (_STACK *)0x0;
    bVar9 = false;
    bVar10 = false;
    bVar11 = false;
    local_51c = 0;
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
    local_4ec = (FILE *)0x0;
    local_4f0 = 0x1e;
    bVar5 = false;
    local_564 = (ENGINE *)0x0;
LAB_0804e076:
    do {
      pcVar14 = *ppcVar37;
      iVar33 = 8;
      pcVar18 = pcVar14;
      pcVar32 = "-inform";
      do {
        if (iVar33 == 0) break;
        iVar33 = iVar33 + -1;
        bVar40 = *pcVar18 == *pcVar32;
        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
        pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
      } while (bVar40);
      if (bVar40) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          local_570 = str2fmt(ppcVar37[1]);
          ppcVar39 = ppcVar37 + 1;
          goto LAB_0804e06e;
        }
LAB_0804e540:
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
        goto LAB_0804e81f;
      }
      iVar33 = 9;
      pcVar18 = pcVar14;
      pcVar32 = "-outform";
      do {
        if (iVar33 == 0) break;
        iVar33 = iVar33 + -1;
        bVar40 = *pcVar18 == *pcVar32;
        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
        pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
      } while (bVar40);
      if (!bVar40) {
        iVar33 = 8;
        pcVar18 = pcVar14;
        pcVar32 = "-engine";
        do {
          if (iVar33 == 0) break;
          iVar33 = iVar33 + -1;
          bVar40 = *pcVar18 == *pcVar32;
          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
          pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
        } while (bVar40);
        if (bVar40) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0804e540;
          local_568 = ppcVar37[1];
          ppcVar39 = ppcVar37 + 1;
        }
        else {
          iVar33 = 0xf;
          pcVar18 = pcVar14;
          pcVar32 = "-keygen_engine";
          do {
            if (iVar33 == 0) break;
            iVar33 = iVar33 + -1;
            bVar40 = *pcVar18 == *pcVar32;
            pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
            pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
          } while (bVar40);
          if (bVar40) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0804e540;
            local_564 = ENGINE_by_id(pcVar14);
            ppcVar39 = ppcVar37 + 1;
            if (local_564 == (ENGINE *)0x0) {
              pcVar14 = "Can\'t find keygen engine %s\n";
              goto LAB_0804e81f;
            }
          }
          else {
            iVar33 = 5;
            pcVar18 = pcVar14;
            pcVar32 = "-key";
            do {
              if (iVar33 == 0) break;
              iVar33 = iVar33 + -1;
              bVar40 = *pcVar18 == *pcVar32;
              pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
              pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
            } while (bVar40);
            if (bVar40) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0804e540;
              local_548 = ppcVar37[1];
              ppcVar39 = ppcVar37 + 1;
            }
            else {
              iVar33 = 8;
              pcVar18 = pcVar14;
              pcVar32 = "-pubkey";
              do {
                if (iVar33 == 0) break;
                iVar33 = iVar33 + -1;
                bVar40 = *pcVar18 == *pcVar32;
                pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
              } while (bVar40);
              ppcVar39 = ppcVar37;
              if (bVar40) {
                bVar9 = true;
              }
              else {
                iVar33 = 5;
                pcVar18 = pcVar14;
                pcVar32 = "-new";
                do {
                  if (iVar33 == 0) break;
                  iVar33 = iVar33 + -1;
                  bVar40 = *pcVar18 == *pcVar32;
                  pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                  pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                } while (bVar40);
                if (!bVar40) {
                  iVar33 = 8;
                  pcVar18 = pcVar14;
                  pcVar32 = "-config";
                  do {
                    if (iVar33 == 0) break;
                    iVar33 = iVar33 + -1;
                    bVar40 = *pcVar18 == *pcVar32;
                    pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                    pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                  } while (bVar40);
                  if (bVar40) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      local_53c = ppcVar37[1];
                      ppcVar39 = ppcVar37 + 1;
                      goto LAB_0804e06e;
                    }
                  }
                  else {
                    iVar33 = 9;
                    pcVar18 = pcVar14;
                    pcVar32 = "-keyform";
                    do {
                      if (iVar33 == 0) break;
                      iVar33 = iVar33 + -1;
                      bVar40 = *pcVar18 == *pcVar32;
                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                      pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                    } while (bVar40);
                    if (bVar40) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_4e4 = str2fmt(ppcVar37[1]);
                        ppcVar39 = ppcVar37 + 1;
                        goto LAB_0804e06e;
                      }
                    }
                    else {
                      bVar40 = *pcVar14 == '-';
                      if ((((bVar40) && (bVar40 = pcVar14[1] == 'i', bVar40)) &&
                          (bVar40 = pcVar14[2] == 'n', bVar40)) &&
                         (bVar40 = pcVar14[3] == '\0', bVar40)) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          local_500 = (_STACK *)ppcVar37[1];
                          ppcVar39 = ppcVar37 + 1;
                          goto LAB_0804e06e;
                        }
                      }
                      else {
                        iVar33 = 5;
                        pcVar18 = pcVar14;
                        pcVar32 = "-out";
                        do {
                          if (iVar33 == 0) break;
                          iVar33 = iVar33 + -1;
                          bVar40 = *pcVar18 == *pcVar32;
                          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                          pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                        } while (bVar40);
                        if (bVar40) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_518 = ppcVar37[1];
                            ppcVar39 = ppcVar37 + 1;
                            goto LAB_0804e06e;
                          }
                        }
                        else {
                          iVar33 = 8;
                          pcVar18 = pcVar14;
                          pcVar32 = "-keyout";
                          do {
                            if (iVar33 == 0) break;
                            iVar33 = iVar33 + -1;
                            bVar40 = *pcVar18 == *pcVar32;
                            pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                            pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                          } while (bVar40);
                          if (bVar40) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_514 = ppcVar37[1];
                              ppcVar39 = ppcVar37 + 1;
                              goto LAB_0804e06e;
                            }
                          }
                          else {
                            iVar33 = 8;
                            pcVar18 = pcVar14;
                            pcVar32 = "-passin";
                            do {
                              if (iVar33 == 0) break;
                              iVar33 = iVar33 + -1;
                              bVar40 = *pcVar18 == *pcVar32;
                              pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                              pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                            } while (bVar40);
                            if (bVar40) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_558 = ppcVar37[1];
                                ppcVar39 = ppcVar37 + 1;
                                goto LAB_0804e06e;
                              }
                            }
                            else {
                              iVar33 = 9;
                              pcVar18 = pcVar14;
                              pcVar32 = "-passout";
                              do {
                                if (iVar33 == 0) break;
                                iVar33 = iVar33 + -1;
                                bVar40 = *pcVar18 == *pcVar32;
                                pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                              } while (bVar40);
                              if (bVar40) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_554 = ppcVar37[1];
                                  ppcVar39 = ppcVar37 + 1;
                                  goto LAB_0804e06e;
                                }
                              }
                              else {
                                iVar33 = 6;
                                pcVar18 = pcVar14;
                                pcVar32 = "-rand";
                                do {
                                  if (iVar33 == 0) break;
                                  iVar33 = iVar33 + -1;
                                  bVar40 = *pcVar18 == *pcVar32;
                                  pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                  pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                } while (bVar40);
                                if (bVar40) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_4d8 = ppcVar37[1];
                                    ppcVar39 = ppcVar37 + 1;
                                    goto LAB_0804e06e;
                                  }
                                }
                                else {
                                  iVar33 = 8;
                                  pcVar18 = pcVar14;
                                  pcVar32 = "-newkey";
                                  do {
                                    if (iVar33 == 0) break;
                                    iVar33 = iVar33 + -1;
                                    bVar40 = *pcVar18 == *pcVar32;
                                    pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                    pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                  } while (bVar40);
                                  if (bVar40) {
                                    param_1 = param_1 + -1;
                                    if (param_1 != 0) {
                                      local_4ec = (FILE *)ppcVar37[1];
                                      bVar41 = true;
                                      ppcVar39 = ppcVar37 + 1;
                                      goto LAB_0804e06e;
                                    }
                                  }
                                  else {
                                    iVar33 = 9;
                                    pcVar18 = pcVar14;
                                    pcVar32 = "-pkeyopt";
                                    do {
                                      if (iVar33 == 0) break;
                                      iVar33 = iVar33 + -1;
                                      bVar40 = *pcVar18 == *pcVar32;
                                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                      pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                    } while (bVar40);
                                    if (bVar40) {
                                      if ((param_1 != 1) &&
                                         ((local_55c != (_STACK *)0x0 ||
                                          (local_55c = sk_new_null(), local_55c != (_STACK *)0x0))))
                                      {
                                        pAVar24 = (ASN1_INTEGER *)sk_push(local_55c,ppcVar37[1]);
joined_r0x0804fda3:
                                        param_1 = param_1 + -1;
                                        ppcVar39 = ppcVar37 + 1;
                                        if (pAVar24 != (ASN1_INTEGER *)0x0) goto LAB_0804e06e;
                                      }
                                    }
                                    else {
                                      iVar33 = 8;
                                      pcVar18 = pcVar14;
                                      pcVar32 = "-sigopt";
                                      do {
                                        if (iVar33 == 0) break;
                                        iVar33 = iVar33 + -1;
                                        bVar40 = *pcVar18 == *pcVar32;
                                        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                        pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                      } while (bVar40);
                                      if (!bVar40) {
                                        iVar33 = 7;
                                        pcVar18 = pcVar14;
                                        pcVar32 = "-batch";
                                        do {
                                          if (iVar33 == 0) break;
                                          iVar33 = iVar33 + -1;
                                          bVar40 = *pcVar18 == *pcVar32;
                                          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                          pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                        } while (bVar40);
                                        if (bVar40) {
                                          batch = 1;
                                        }
                                        else {
                                          iVar33 = 8;
                                          pcVar18 = pcVar14;
                                          pcVar32 = "-newhdr";
                                          do {
                                            if (iVar33 == 0) break;
                                            iVar33 = iVar33 + -1;
                                            bVar40 = *pcVar18 == *pcVar32;
                                            pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                            pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                          } while (bVar40);
                                          if (bVar40) {
                                            bVar11 = true;
                                          }
                                          else {
                                            iVar33 = 9;
                                            pcVar18 = pcVar14;
                                            pcVar32 = "-modulus";
                                            do {
                                              if (iVar33 == 0) break;
                                              iVar33 = iVar33 + -1;
                                              bVar40 = *pcVar18 == *pcVar32;
                                              pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                              pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                            } while (bVar40);
                                            if (bVar40) {
                                              bVar8 = true;
                                            }
                                            else {
                                              iVar33 = 8;
                                              pcVar18 = pcVar14;
                                              pcVar32 = "-verify";
                                              do {
                                                if (iVar33 == 0) break;
                                                iVar33 = iVar33 + -1;
                                                bVar40 = *pcVar18 == *pcVar32;
                                                pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                              } while (bVar40);
                                              if (bVar40) {
                                                bVar3 = 1;
                                              }
                                              else {
                                                iVar33 = 7;
                                                pcVar18 = pcVar14;
                                                pcVar32 = "-nodes";
                                                do {
                                                  if (iVar33 == 0) break;
                                                  iVar33 = iVar33 + -1;
                                                  bVar40 = *pcVar18 == *pcVar32;
                                                  pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                  pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                } while (bVar40);
                                                if (bVar40) {
                                                  bVar12 = true;
                                                }
                                                else {
                                                  iVar33 = 7;
                                                  pcVar18 = pcVar14;
                                                  pcVar32 = "-noout";
                                                  do {
                                                    if (iVar33 == 0) break;
                                                    iVar33 = iVar33 + -1;
                                                    bVar40 = *pcVar18 == *pcVar32;
                                                    pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                    pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                  } while (bVar40);
                                                  if (bVar40) {
                                                    bVar6 = true;
                                                  }
                                                  else {
                                                    iVar33 = 9;
                                                    pcVar18 = pcVar14;
                                                    pcVar32 = "-verbose";
                                                    do {
                                                      if (iVar33 == 0) break;
                                                      iVar33 = iVar33 + -1;
                                                      bVar40 = *pcVar18 == *pcVar32;
                                                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                      pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                    } while (bVar40);
                                                    if (bVar40) {
                                                      bVar4 = true;
                                                    }
                                                    else {
                                                      iVar33 = 6;
                                                      pcVar18 = pcVar14;
                                                      pcVar32 = "-utf8";
                                                      do {
                                                        if (iVar33 == 0) break;
                                                        iVar33 = iVar33 + -1;
                                                        bVar40 = *pcVar18 == *pcVar32;
                                                        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                        pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                      } while (bVar40);
                                                      if (!bVar40) {
                                                        iVar33 = 9;
                                                        pcVar18 = pcVar14;
                                                        pcVar32 = "-nameopt";
                                                        do {
                                                          if (iVar33 == 0) break;
                                                          iVar33 = iVar33 + -1;
                                                          bVar40 = *pcVar18 == *pcVar32;
                                                          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                          pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                        } while (bVar40);
                                                        if (bVar40) {
                                                          if (param_1 != 1) {
                                                            pAVar24 = (ASN1_INTEGER *)
                                                                      set_name_ex(&local_4c4,
                                                                                  ppcVar37[1]);
                                                            goto joined_r0x0804fda3;
                                                          }
                                                        }
                                                        else {
                                                          iVar33 = 8;
                                                          pcVar18 = pcVar14;
                                                          pcVar32 = "-reqopt";
                                                          do {
                                                            if (iVar33 == 0) break;
                                                            iVar33 = iVar33 + -1;
                                                            bVar40 = *pcVar18 == *pcVar32;
                                                            pcVar18 = pcVar18 + (uint)bVar42 * -2 +
                                                                                1;
                                                            pcVar32 = pcVar32 + (uint)bVar42 * -2 +
                                                                                1;
                                                          } while (bVar40);
                                                          if (!bVar40) {
                                                            iVar33 = 9;
                                                            pcVar18 = pcVar14;
                                                            pcVar32 = "-subject";
                                                            do {
                                                              if (iVar33 == 0) break;
                                                              iVar33 = iVar33 + -1;
                                                              bVar40 = *pcVar18 == *pcVar32;
                                                              pcVar18 = pcVar18 + (uint)bVar42 * -2
                                                                                  + 1;
                                                              pcVar32 = pcVar32 + (uint)bVar42 * -2
                                                                                  + 1;
                                                            } while (bVar40);
                                                            if (bVar40) {
                                                              bVar10 = true;
                                                            }
                                                            else {
                                                              iVar33 = 6;
                                                              pcVar18 = pcVar14;
                                                              pcVar32 = "-text";
                                                              do {
                                                                if (iVar33 == 0) break;
                                                                iVar33 = iVar33 + -1;
                                                                bVar40 = *pcVar18 == *pcVar32;
                                                                pcVar18 = pcVar18 + (uint)bVar42 *
                                                                                    -2 + 1;
                                                                pcVar32 = pcVar32 + (uint)bVar42 *
                                                                                    -2 + 1;
                                                              } while (bVar40);
                                                              if (bVar40) {
                                                                bVar7 = true;
                                                              }
                                                              else {
                                                                iVar33 = 6;
                                                                pcVar18 = pcVar14;
                                                                pcVar32 = "-x509";
                                                                do {
                                                                  if (iVar33 == 0) break;
                                                                  iVar33 = iVar33 + -1;
                                                                  bVar40 = *pcVar18 == *pcVar32;
                                                                  pcVar18 = pcVar18 + (uint)bVar42 *
                                                                                      -2 + 1;
                                                                  pcVar32 = pcVar32 + (uint)bVar42 *
                                                                                      -2 + 1;
                                                                } while (bVar40);
                                                                if (bVar40) {
                                                                  bVar5 = true;
                                                                }
                                                                else {
                                                                  iVar33 = 0xd;
                                                                  pcVar18 = pcVar14;
                                                                  pcVar32 = "-asn1-kludge";
                                                                  do {
                                                                    if (iVar33 == 0) break;
                                                                    iVar33 = iVar33 + -1;
                                                                    bVar40 = *pcVar18 == *pcVar32;
                                                                    pcVar18 = pcVar18 + (uint)bVar42
                                                                                        * -2 + 1;
                                                                    pcVar32 = pcVar32 + (uint)bVar42
                                                                                        * -2 + 1;
                                                                  } while (bVar40);
                                                                  if (bVar40) {
                                                                    local_51c = 1;
                                                                  }
                                                                  else {
                                                                    iVar33 = 0x10;
                                                                    pcVar18 = pcVar14;
                                                                    pcVar32 = "-no-asn1-kludge";
                                                                    do {
                                                                      if (iVar33 == 0) break;
                                                                      iVar33 = iVar33 + -1;
                                                                      bVar40 = *pcVar18 == *pcVar32;
                                                                      pcVar18 = pcVar18 + (uint)
                                                  bVar42 * -2 + 1;
                                                  pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                  } while (bVar40);
                                                  if (bVar40) {
                                                    local_51c = 0;
                                                  }
                                                  else {
                                                    iVar33 = 6;
                                                    pcVar18 = pcVar14;
                                                    pcVar32 = "-subj";
                                                    do {
                                                      if (iVar33 == 0) break;
                                                      iVar33 = iVar33 + -1;
                                                      bVar40 = *pcVar18 == *pcVar32;
                                                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                      pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                    } while (bVar40);
                                                    if (bVar40) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 == 0) goto LAB_0804e540;
                                                      local_538 = ppcVar37[1];
                                                      ppcVar39 = ppcVar37 + 1;
                                                    }
                                                    else {
                                                      iVar33 = 0x10;
                                                      pcVar18 = pcVar14;
                                                      pcVar32 = "-multivalue-rdn";
                                                      do {
                                                        if (iVar33 == 0) break;
                                                        iVar33 = iVar33 + -1;
                                                        bVar40 = *pcVar18 == *pcVar32;
                                                        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                        pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                      } while (bVar40);
                                                      if (!bVar40) {
                                                        iVar33 = 6;
                                                        pcVar18 = pcVar14;
                                                        pcVar32 = "-days";
                                                        do {
                                                          if (iVar33 == 0) break;
                                                          iVar33 = iVar33 + -1;
                                                          bVar40 = *pcVar18 == *pcVar32;
                                                          pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                          pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                        } while (bVar40);
                                                        if (bVar40) {
                                                          param_1 = param_1 + -1;
                                                          if (param_1 != 0) {
                                                            ppcVar39 = ppcVar37 + 1;
                                                            lVar19 = strtol(ppcVar37[1],(char **)0x0
                                                                            ,10);
                                                            local_4f0 = 0x1e;
                                                            if (lVar19 != 0) {
                                                              local_4f0 = lVar19;
                                                            }
                                                            goto LAB_0804e06e;
                                                          }
                                                        }
                                                        else {
                                                          iVar33 = 0xc;
                                                          pcVar18 = pcVar14;
                                                          pcVar32 = "-set_serial";
                                                          do {
                                                            if (iVar33 == 0) break;
                                                            iVar33 = iVar33 + -1;
                                                            bVar40 = *pcVar18 == *pcVar32;
                                                            pcVar18 = pcVar18 + (uint)bVar42 * -2 +
                                                                                1;
                                                            pcVar32 = pcVar32 + (uint)bVar42 * -2 +
                                                                                1;
                                                          } while (bVar40);
                                                          if (bVar40) {
                                                            if (param_1 != 1) {
                                                              local_54c = s2i_ASN1_INTEGER((
                                                  X509V3_EXT_METHOD *)0x0,ppcVar37[1]);
                                                  pAVar24 = local_54c;
                                                  goto joined_r0x0804fda3;
                                                  }
                                                  }
                                                  else {
                                                    iVar33 = 0xc;
                                                    pcVar18 = pcVar14;
                                                    pcVar32 = "-extensions";
                                                    do {
                                                      if (iVar33 == 0) break;
                                                      iVar33 = iVar33 + -1;
                                                      bVar40 = *pcVar18 == *pcVar32;
                                                      pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                      pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                    } while (bVar40);
                                                    if (!bVar40) {
                                                      iVar33 = 9;
                                                      pcVar18 = pcVar14;
                                                      pcVar32 = "-reqexts";
                                                      do {
                                                        if (iVar33 == 0) break;
                                                        iVar33 = iVar33 + -1;
                                                        bVar40 = *pcVar18 == *pcVar32;
                                                        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                                                        pcVar32 = pcVar32 + (uint)bVar42 * -2 + 1;
                                                      } while (bVar40);
                                                      if (bVar40) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 == 0) goto LAB_0804e540;
                                                        local_528 = (FILE *)ppcVar37[1];
                                                        ppcVar39 = ppcVar37 + 1;
                                                      }
                                                      else {
                                                        local_508 = EVP_get_digestbyname
                                                                              (pcVar14 + 1);
                                                        local_4f4 = local_508;
                                                        if (local_508 == (EVP_MD *)0x0) {
                                                          BIO_printf(bio_err,"unknown option %s\n",
                                                                     *ppcVar37);
                                                          goto LAB_0804e540;
                                                        }
                                                      }
                                                      goto LAB_0804e06e;
                                                    }
                                                    param_1 = param_1 + -1;
                                                    if (param_1 != 0) {
                                                      local_530 = ppcVar37[1];
                                                      ppcVar39 = ppcVar37 + 1;
                                                      goto LAB_0804e06e;
                                                    }
                                                  }
                                                  }
                                                  goto LAB_0804e540;
                                                  }
                                                  local_4fc = 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_0804e06e;
                                                  }
                                                  if (param_1 != 1) {
                                                    pAVar24 = (ASN1_INTEGER *)
                                                              set_cert_ex(&local_4c0,ppcVar37[1]);
                                                    goto joined_r0x0804fda3;
                                                  }
                                                  }
                                                  goto LAB_0804e540;
                                                  }
                                                  local_534 = 0x1000;
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                        goto LAB_0804e06e;
                                      }
                                      if ((param_1 != 1) &&
                                         ((local_550 != (_STACK *)0x0 ||
                                          (local_550 = sk_new_null(), local_550 != (_STACK *)0x0))))
                                      {
                                        pAVar24 = (ASN1_INTEGER *)sk_push(local_550,ppcVar37[1]);
                                        goto joined_r0x0804fda3;
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
                  goto LAB_0804e540;
                }
                bVar41 = true;
              }
            }
          }
        }
LAB_0804e06e:
        param_1 = param_1 + -1;
        bVar40 = param_1 == 0;
        ppcVar37 = ppcVar39 + 1;
        if (bVar40) break;
        goto LAB_0804e076;
      }
      if (param_1 == 1) goto LAB_0804e540;
      local_56c = str2fmt(ppcVar37[1]);
      param_1 = param_1 + -2;
      bVar40 = param_1 == 0;
      ppcVar37 = ppcVar37 + 2;
    } while (!bVar40);
  }
  ERR_load_crypto_strings();
  iVar33 = app_passwd(bio_err,local_558,local_554,&local_4ac,&local_4a8);
  if (iVar33 != 0) {
    if (local_53c != (char *)0x0) {
      local_4a0.flags = -1;
      if (bVar4) {
        BIO_printf(bio_err,"Using configuration from %s\n",local_53c);
      }
      req_conf = NCONF_new((CONF_METHOD *)0x0);
      iVar33 = NCONF_load(req_conf,local_53c,&local_4a0.flags);
      if (iVar33 != 0) goto LAB_0804e14a;
      pcVar14 = "error on line %ld of %s\n";
      goto LAB_0804e81f;
    }
    req_conf = config;
    if (config == (CONF *)0x0) {
      BIO_printf(bio_err,"Unable to load config info from %s\n",default_config_file);
      if (!bVar41) goto LAB_0804e14a;
      goto LAB_0804e82d;
    }
    if (bVar4) {
      BIO_printf(bio_err,"Using configuration from %s\n",default_config_file);
LAB_0804e14a:
      if (req_conf != (CONF *)0x0) goto LAB_0804e153;
    }
    else {
LAB_0804e153:
      iVar33 = load_config(bio_err,req_conf);
      if (iVar33 == 0) goto LAB_0804e82d;
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
    if (iVar33 == 0) goto LAB_0804e82d;
    pEVar21 = local_508;
    if (local_4f4 == (EVP_MD *)0x0) {
      pcVar14 = NCONF_get_string(req_conf,"req","default_md");
      if (pcVar14 == (char *)0x0) {
        ERR_clear_error();
      }
      else {
        pEVar21 = EVP_get_digestbyname(pcVar14);
        if (pEVar21 == (EVP_MD *)0x0) {
          pEVar21 = local_508;
        }
      }
    }
    local_508 = pEVar21;
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
        goto LAB_0804e81f;
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
        goto LAB_0804e81f;
      }
    }
    if (local_534 == 0x1000) {
LAB_0804e2d8:
      local_534 = 0x1000;
    }
    else {
      pcVar14 = NCONF_get_string(req_conf,"req","utf8");
      if (pcVar14 == (char *)0x0) {
        ERR_clear_error();
      }
      else if ((((*pcVar14 == 'y') && (pcVar14[1] == 'e')) && (pcVar14[2] == 's')) &&
              (pcVar14[3] == '\0')) goto LAB_0804e2d8;
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
        goto LAB_0804e81f;
      }
    }
    pBVar16 = BIO_s_file();
    local_560 = BIO_new(pBVar16);
    pBVar16 = BIO_s_file();
    pBVar15 = BIO_new(pBVar16);
    bVar40 = local_560 == (BIO *)0x0 || pBVar15 == (BIO *)0x0;
    if (bVar40) goto LAB_0804e837;
    pcVar14 = (char *)0x0;
    uVar17 = setup_engine(bio_err,local_568,0);
    if (local_548 != (char *)0x0) {
      local_4b8 = (EVP_PKEY *)load_key(bio_err,local_548,local_4e4,0,local_4ac,uVar17,"Private Key")
      ;
      if (local_4b8 == (EVP_PKEY *)0x0) goto LAB_0804e837;
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
      if (local_4ec == (FILE *)0x0) {
        pEVar38 = (EVP_PKEY *)0x0;
LAB_0804ee94:
        if ((local_4b0 < 1) &&
           (iVar33 = NCONF_get_number_e(req_conf,"req","default_bits",&local_4b0), iVar33 == 0)) {
          local_4b0 = 0x200;
        }
        else if ((local_4b0 < 0x180) && ((local_4b4 == 6 || (local_4b4 == 0x74)))) {
          x = (X509_REQ *)0x0;
          x_00 = (X509 *)0x0;
          BIO_printf(bio_err,"private key length is too short,\n");
          BIO_printf(bio_err,"it needs to be at least %d bits, not %ld\n",0x180,local_4b0);
          goto LAB_0804e83d;
        }
        if ((pEVar38 != (EVP_PKEY *)0x0) ||
           (pEVar38 = (EVP_PKEY *)set_keygen_ctx(&local_4b0,&local_4bc,local_564),
           pEVar38 != (EVP_PKEY *)0x0)) {
          if (local_55c != (_STACK *)0x0) {
            for (iVar33 = 0; iVar29 = sk_num(local_55c), iVar33 < iVar29; iVar33 = iVar33 + 1) {
              pvVar28 = sk_value(local_55c,iVar33);
              iVar29 = pkey_ctrl_string(pEVar38,pvVar28);
              if (iVar29 < 1) {
                x = (X509_REQ *)0x0;
                BIO_printf(bio_err,"parameter error \"%s\"\n",pvVar28);
                x_00 = (X509 *)0x0;
                ERR_print_errors(bio_err);
                goto LAB_0804e83d;
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
            goto LAB_0804e83d;
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
            local_500 = (_STACK *)local_514;
            if (lVar19 < 1) goto LAB_0804f95a;
          }
          pcVar14 = NCONF_get_string(req_conf,"req","encrypt_rsa_key");
          local_50c = pEVar13;
          if (pcVar14 == (char *)0x0) {
            ERR_clear_error();
            pcVar14 = NCONF_get_string(req_conf,"req","encrypt_key");
            if (pcVar14 != (char *)0x0) goto LAB_0804f87d;
            ERR_clear_error();
          }
          else {
LAB_0804f87d:
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
                iVar29 = PEM_write_bio_PrivateKey
                                   (pBVar15,local_4b8,pEVar13,(uchar *)0x0,0,(undefined1 *)0x0,
                                    local_4a8), iVar29 == 0) {
            uVar22 = ERR_peek_error();
            if (((uVar22 & 0xfff) != 0x6d) || (iVar33 == 3)) goto LAB_0804e837;
            ERR_clear_error();
            iVar33 = iVar33 + 1;
          }
          x = (X509_REQ *)0x0;
          BIO_printf(bio_err,"-----\n");
          goto LAB_0804f094;
        }
      }
      else {
        pEVar38 = (EVP_PKEY *)set_keygen_ctx(&local_4b0,&local_4bc,local_564);
        if (pEVar38 != (EVP_PKEY *)0x0) goto LAB_0804ee94;
      }
      goto LAB_0804e839;
    }
    if (!bVar41) {
      if (local_500 == (_STACK *)0x0) {
        pcVar14 = (char *)0x0;
        BIO_ctrl(local_560,0x6a,0,stdin);
LAB_0804e449:
        if (local_570 == 1) {
          x = d2i_X509_REQ_bio(local_560,(X509_REQ **)0x0);
LAB_0804f084:
          local_51c = -1;
          if (x != (X509_REQ *)0x0) goto LAB_0804f094;
          pcVar18 = "unable to load X509 request\n";
          goto LAB_080500ec;
        }
        if (local_570 == 3) {
          pcVar14 = (char *)0x0;
          x = PEM_read_bio_X509_REQ(local_560,(X509_REQ **)0x0,(undefined1 *)0x0,(void *)0x0);
          goto LAB_0804f084;
        }
        pEVar38 = (EVP_PKEY *)0x0;
        x = (X509_REQ *)0x0;
        x_00 = (X509 *)0x0;
        BIO_printf(bio_err,"bad input format specified for X509 request\n");
      }
      else {
        pcVar14 = (char *)0x3;
        lVar19 = BIO_ctrl(local_560,0x6c,3,local_500);
        if (0 < lVar19) goto LAB_0804e449;
LAB_0804f95a:
        perror((char *)local_500);
        pEVar38 = (EVP_PKEY *)0x0;
        x = (X509_REQ *)0x0;
        x_00 = (X509 *)0x0;
      }
      goto LAB_0804e83d;
    }
    x = (X509_REQ *)0x0;
LAB_0804f094:
    if (!(bool)(bVar41 | bVar5)) {
LAB_0804f176:
      bVar12 = !bVar5;
      bVar41 = local_538 != (char *)0x0 && bVar12;
      if (local_538 != (char *)0x0 && bVar12) {
        bVar12 = bVar41;
        if (bVar4) {
          BIO_printf(bio_err,"Modifying Request\'s Subject\n");
          print_name(bio_err,"old subject=",x->req_info->subject,local_4c4);
          iVar33 = build_subject(local_4fc);
          if (iVar33 == 0) goto LAB_08050ca8;
          pXVar2 = x->req_info;
          (pXVar2->enc).modified = 1;
          print_name(bio_err,"new subject=",pXVar2->subject,local_4c4);
        }
        else {
          iVar33 = build_subject(local_4fc);
          if (iVar33 == 0) {
LAB_08050ca8:
            pcVar18 = "ERROR: cannot modify subject\n";
            goto LAB_080500ec;
          }
          (x->req_info->enc).modified = 1;
        }
      }
      if ((bool)(bVar3 & bVar12)) {
        if (local_4b8 == (EVP_PKEY *)0x0) {
          local_4b8 = X509_REQ_get_pubkey(x);
          if (local_4b8 == (EVP_PKEY *)0x0) goto LAB_0804fead;
          iVar33 = X509_REQ_verify(x,local_4b8);
          EVP_PKEY_free(local_4b8);
          local_4b8 = (EVP_PKEY *)0x0;
        }
        else {
          iVar33 = X509_REQ_verify(x,local_4b8);
        }
        if (iVar33 < 0) goto LAB_0804fead;
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
LAB_0804f21b:
      if (((!bVar6) || (bVar7)) || ((bool)(bVar10 | bVar9 | bVar8))) {
        if (local_518 == (char *)0x0) {
          BIO_ctrl(pBVar15,0x6a,0,stdout);
        }
        else {
          if ((local_514 == (char *)0x0) || (iVar33 = strcmp(local_518,local_514), iVar33 != 0)) {
            iVar33 = BIO_ctrl(pBVar15,0x6c,5,local_518);
          }
          else {
            iVar33 = BIO_ctrl(pBVar15,0x6c,9,local_518);
          }
          if (iVar33 == 0) {
            pEVar38 = (EVP_PKEY *)0x0;
            perror(local_518);
            goto LAB_0804e83d;
          }
        }
        if (bVar9) {
          pEVar38 = X509_REQ_get_pubkey(x);
          if (pEVar38 == (EVP_PKEY *)0x0) {
            BIO_printf(bio_err,"Error getting public key\n");
            ERR_print_errors(bio_err);
            goto LAB_0804e83d;
          }
          PEM_write_bio_PUBKEY(pBVar15,pEVar38);
          EVP_PKEY_free(pEVar38);
        }
        if (bVar7) {
          if (bVar40) {
            X509_print_ex(pBVar15,x_00,local_4c4,local_4c0);
            if (bVar10) goto LAB_0804f2cf;
            if (!bVar8) goto LAB_0804f367;
LAB_0804f2f7:
            pEVar38 = X509_get_pubkey(x_00);
          }
          else {
            X509_REQ_print_ex(pBVar15,x,local_4c4,local_4c0);
            if (bVar10) {
LAB_0804f476:
              print_name(pBVar15,"subject=",x->req_info->subject,local_4c4);
            }
            if (!bVar8) goto LAB_0804f367;
LAB_0804f49c:
            pEVar38 = X509_REQ_get_pubkey(x);
          }
          if (pEVar38 == (EVP_PKEY *)0x0) {
            fwrite("Modulus=unavailable\n",1,0x14,stdout);
            goto LAB_0804e83d;
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
          if (!bVar40) goto LAB_0804f476;
LAB_0804f2cf:
          uVar22 = local_4c4;
          pXVar20 = X509_get_subject_name(x_00);
          print_name(pBVar15,"subject=",pXVar20,uVar22);
          if (bVar8) goto LAB_0804f2f7;
        }
        else if (bVar8) {
          if (bVar40) goto LAB_0804f2f7;
          goto LAB_0804f49c;
        }
LAB_0804f367:
        if (!(bool)(bVar5 | bVar6)) {
          if (local_56c == 1) {
            iVar33 = i2d_X509_REQ_bio(pBVar15,x);
LAB_0804f39f:
            if (iVar33 == 0) {
              pEVar38 = (EVP_PKEY *)0x0;
              BIO_printf(bio_err,"unable to write X509 request\n");
              goto LAB_0804e83d;
            }
            goto LAB_0804f3a7;
          }
          if (local_56c == 3) {
            if (bVar11) {
              iVar33 = PEM_write_bio_X509_REQ_NEW(pBVar15,x);
            }
            else {
              iVar33 = PEM_write_bio_X509_REQ(pBVar15,x);
            }
            goto LAB_0804f39f;
          }
LAB_0804f3c8:
          pEVar38 = (EVP_PKEY *)0x0;
          BIO_printf(bio_err,"bad output format specified for outfile\n");
          goto LAB_0804e83d;
        }
LAB_0804f3a7:
        if (((!bVar6) && (bVar40)) && (x_00 != (X509 *)0x0)) {
          if (local_56c == 1) {
            iVar33 = i2d_X509_bio(pBVar15,x_00);
          }
          else {
            if (local_56c != 3) goto LAB_0804f3c8;
            iVar33 = PEM_write_bio_X509(pBVar15,x_00);
          }
          if (iVar33 == 0) {
            BIO_printf(bio_err,"unable to write X509 certificate\n");
            goto LAB_0804f0ee;
          }
        }
      }
      pEVar38 = (EVP_PKEY *)0x0;
      local_570 = 0;
      goto LAB_0804e856;
    }
    if (local_4b8 != (EVP_PKEY *)0x0) {
      if (x == (X509_REQ *)0x0) {
        x = X509_REQ_new();
        pEVar38 = local_4b8;
        if (x != (X509_REQ *)0x0) {
          pbVar25 = (byte *)NCONF_get_string(req_conf,"req","prompt");
          if (pbVar25 == (byte *)0x0) {
            ERR_clear_error();
            bVar41 = false;
          }
          else {
            iVar33 = 0x6e - (uint)*pbVar25;
            if ((iVar33 == 0) && (iVar33 = 0x6f - (uint)pbVar25[1], iVar33 == 0)) {
              iVar33 = -(uint)pbVar25[2];
            }
            bVar41 = iVar33 == 0;
          }
          pFVar26 = (FILE *)NCONF_get_string(req_conf,"req","distinguished_name");
          if (pFVar26 == (FILE *)0x0) {
            pcVar14 = "distinguished_name";
            BIO_printf(bio_err,"unable to find \'%s\' in config\n","distinguished_name");
          }
          else {
            p_Var27 = (_STACK *)NCONF_get_section(req_conf,(char *)pFVar26);
            if (p_Var27 == (_STACK *)0x0) {
              BIO_printf(bio_err,"unable to get \'%s\' section\n",pFVar26);
              pcVar14 = (char *)pFVar26;
            }
            else {
              pcVar14 = "attributes";
              section = (FILE *)NCONF_get_string(req_conf,"req","attributes");
              if (section == (FILE *)0x0) {
                ERR_clear_error();
                local_500 = (_STACK *)0x0;
              }
              else {
                local_500 = (_STACK *)NCONF_get_section(req_conf,(char *)section);
                if (local_500 == (_STACK *)0x0) {
                  BIO_printf(bio_err,"unable to get \'%s\' section\n",section);
                  pcVar14 = (char *)section;
                  goto LAB_080500af;
                }
              }
              iVar33 = X509_REQ_set_version(x,0);
              if (iVar33 != 0) {
                if (bVar41) {
                  pXVar20 = x->req_info->subject;
                  for (iVar33 = 0; iVar29 = sk_num(p_Var27), iVar33 < iVar29; iVar33 = iVar33 + 1) {
                    pvVar28 = sk_value(p_Var27,iVar33);
                    pbVar25 = *(byte **)((int)pvVar28 + 4);
                    bVar42 = *pbVar25;
                    pbVar34 = pbVar25;
                    while (bVar42 != 0) {
                      if (((bVar42 & 0xfd) == 0x2c) || (bVar42 == 0x3a)) {
                        bVar42 = pbVar34[1];
                        if (bVar42 != 0) {
                          pbVar25 = pbVar34 + 1;
                        }
                        break;
                      }
                      pbVar34 = pbVar34 + 1;
                      bVar42 = *pbVar34;
                    }
                    pcVar14 = (char *)-(uint)(bVar42 == 0x2b);
                    iVar29 = X509_NAME_add_entry_by_txt
                                       (pXVar20,(char *)pbVar25,local_534,
                                        *(uchar **)((int)pvVar28 + 8),-1,-1,(int)pcVar14);
                    if (iVar29 == 0) goto LAB_080500af;
                  }
                  iVar33 = X509_NAME_entry_count(pXVar20);
                  if (iVar33 == 0) {
LAB_08050891:
                    BIO_printf(bio_err,"error, no objects specified in config file\n");
                  }
                  else {
                    if (!bVar5) {
                      for (iVar33 = 0; iVar29 = sk_num(local_500), iVar33 < iVar29;
                          iVar33 = iVar33 + 1) {
                        pvVar28 = sk_value(local_500,iVar33);
                        iVar29 = X509_REQ_add1_attr_by_txt
                                           (x,*(char **)((int)pvVar28 + 4),local_534,
                                            *(uchar **)((int)pvVar28 + 8),-1);
                        if (iVar29 == 0) goto LAB_080500af;
                      }
                    }
LAB_08050178:
                    iVar33 = X509_REQ_set_pubkey(x,pEVar38);
                    if (iVar33 != 0) {
                      if ((0 < local_51c) &&
                         (iVar33 = sk_num((_STACK *)x->req_info->attributes), iVar33 == 0)) {
                        sk_free((_STACK *)x->req_info->attributes);
                        x->req_info->attributes = (stack_st_X509_ATTRIBUTE *)0x0;
                      }
                      local_538 = (char *)0x0;
                      goto LAB_0804f0b9;
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
                    BIO_printf(bio_err,"There are quite a few fields but you can leave some blank\n"
                              );
                    BIO_printf(bio_err,"For some fields there will be a default value,\n");
                    BIO_printf(bio_err,"If you enter \'.\', the field will be left blank.\n");
                    BIO_printf(bio_err,"-----\n");
                  }
                  iVar33 = sk_num(p_Var27);
                  if (iVar33 == 0) {
                    BIO_printf(bio_err,"No template, please set one up.\n");
                  }
                  else {
                    local_4f4 = (EVP_MD *)0xffffffff;
LAB_080502a1:
                    do {
                      do {
                        do {
                          local_4f4 = (EVP_MD *)((int)local_4f4 + 1);
                          iVar33 = sk_num(p_Var27);
                          if (iVar33 <= (int)local_4f4) {
                            iVar33 = X509_NAME_entry_count(pXVar20);
                            if (iVar33 == 0) goto LAB_08050891;
                            if ((bVar5) || (local_500 == (_STACK *)0x0)) goto LAB_08050178;
                            iVar33 = sk_num(local_500);
                            if ((0 < iVar33) && (batch == 0)) {
                              BIO_printf(bio_err,
                                         "\nPlease enter the following \'extra\' attributes\n");
                              BIO_printf(bio_err,"to be sent with your certificate request\n");
                            }
                            local_538 = (char *)0x0;
                            goto LAB_08050844;
                          }
                          pvVar28 = sk_value(p_Var27,(int)local_4f4);
                          pbVar25 = *(byte **)((int)pvVar28 + 4);
                          iVar33 = check_end();
                        } while ((((iVar33 == 0) || (iVar33 = check_end(), iVar33 == 0)) ||
                                 (iVar33 = check_end(), iVar33 == 0)) ||
                                (iVar33 = check_end(), iVar33 == 0));
                        bVar42 = *pbVar25;
                        pbVar34 = pbVar25;
                        bVar1 = bVar42;
                        if (bVar42 == 0) {
                          local_4ec = (FILE *)0x0;
                        }
                        else {
                          do {
                            if (((bVar1 & 0xfd) == 0x2c) || (bVar1 == 0x3a)) {
                              if (pbVar34[1] != 0) {
                                pbVar25 = pbVar34 + 1;
                                bVar42 = pbVar34[1];
                              }
                              break;
                            }
                            pbVar34 = pbVar34 + 1;
                            bVar1 = *pbVar34;
                          } while (bVar1 != 0);
                          local_4ec = (FILE *)0x0;
                          if (bVar42 == 0x2b) {
                            pbVar25 = pbVar25 + 1;
                            local_4ec = (FILE *)0xffffffff;
                          }
                        }
                        iVar33 = OBJ_txt2nid((char *)pbVar25);
                      } while (iVar33 == 0);
                      iVar29 = BIO_snprintf(local_484,100,"%s_default",
                                            *(undefined4 *)((int)pvVar28 + 4));
                      if (99 < iVar29) goto LAB_08050786;
                      pcVar18 = NCONF_get_string(req_conf,(char *)pFVar26,local_484);
                      if (pcVar18 == (char *)0x0) {
                        pcVar18 = "";
                        ERR_clear_error();
                      }
                      BIO_snprintf(local_484,100,"%s_value",*(undefined4 *)((int)pvVar28 + 4));
                      src = (FILE *)NCONF_get_string(req_conf,(char *)pFVar26,local_484);
                      if (src == (FILE *)0x0) {
                        ERR_clear_error();
                      }
                      BIO_snprintf(local_484,100,"%s_min",*(undefined4 *)((int)pvVar28 + 4));
                      iVar29 = NCONF_get_number_e(req_conf,(char *)pFVar26,local_484,&local_4a4);
                      if (iVar29 == 0) {
                        ERR_clear_error();
                        local_4a4 = -1;
                      }
                      BIO_snprintf(local_484,100,"%s_max",*(undefined4 *)((int)pvVar28 + 4));
                      iVar29 = NCONF_get_number_e(req_conf,(char *)pFVar26,local_484,
                                                  &local_4a0.flags);
                      if (iVar29 == 0) {
                        ERR_clear_error();
                        local_4a0.flags = -1;
                      }
                      uVar17 = *(undefined4 *)((int)pvVar28 + 8);
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
                            pcVar32 = fgets(&local_420,0x400,stdin);
                            if (pcVar32 != (char *)0x0) goto LAB_08050539;
                            goto LAB_080500af;
                          }
                          local_420 = '\n';
                          cStack_41f = '\0';
LAB_0805070d:
                          if (*pcVar18 == '\0') goto LAB_080502a1;
                          BUF_strlcpy(&local_420,pcVar18,0x400);
                          pcVar14 = (char *)0x400;
                          BUF_strlcat(&local_420,"\n",0x400);
                          puVar31 = (uint *)&local_420;
                        }
                        else {
                          BUF_strlcpy(&local_420,(char *)src,0x400);
                          BUF_strlcat(&local_420,"\n",0x400);
                          pcVar14 = (char *)src;
                          BIO_printf(bio_err,"%s\n",src);
LAB_08050539:
                          if (local_420 == '\0') goto LAB_080500af;
                          if (local_420 == '\n') goto LAB_0805070d;
                          puVar31 = (uint *)&local_420;
                          if ((local_420 == '.') && (cStack_41f == '\n')) goto LAB_080502a1;
                        }
                        do {
                          puVar30 = puVar31;
                          uVar35 = *puVar30 + 0xfefefeff & ~*puVar30;
                          uVar36 = uVar35 & 0x80808080;
                          puVar31 = puVar30 + 1;
                        } while (uVar36 == 0);
                        bVar41 = (uVar35 & 0x8080) == 0;
                        if (bVar41) {
                          uVar36 = uVar36 >> 0x10;
                        }
                        if (bVar41) {
                          puVar31 = (uint *)((int)puVar30 + 6);
                        }
                        iVar29 = -(int)&local_420 - (uint)CARRY1((byte)uVar36,(byte)uVar36);
                        if (*(uchar *)((int)puVar31 + (int)(auStack_424 + iVar29)) != '\n')
                        goto LAB_080506d1;
                        *(uchar *)((int)puVar31 + (int)(auStack_424 + iVar29)) = '\0';
                        iVar29 = req_check_len();
                      } while (iVar29 == 0);
                      iVar33 = X509_NAME_add_entry_by_NID
                                         (pXVar20,iVar33,local_534,(uchar *)&local_420,-1,-1,
                                          (int)local_4ec);
                      pcVar14 = (char *)local_4ec;
                    } while (iVar33 != 0);
                  }
                }
                else {
                  iVar33 = build_subject(local_4fc);
                  if (iVar33 != 0) goto LAB_08050178;
                }
              }
            }
          }
          goto LAB_080500af;
        }
LAB_0804fead:
        pEVar38 = (EVP_PKEY *)0x0;
        x_00 = (X509 *)0x0;
        goto LAB_0804e83d;
      }
LAB_0804f0b9:
      if (!bVar5) {
        X509V3_set_ctx(&local_4a0,(X509 *)0x0,(X509 *)0x0,x,(X509_CRL *)0x0,0);
        X509V3_set_nconf(&local_4a0,req_conf);
        if ((local_528 == (FILE *)0x0) ||
           (pcVar14 = (char *)local_528,
           iVar33 = X509V3_EXT_REQ_add_nconf(req_conf,&local_4a0,(char *)local_528,x), iVar33 != 0))
        {
          iVar33 = do_X509_REQ_sign(bio_err,x,local_4b8,local_508,local_550);
          if (iVar33 != 0) goto LAB_0804f176;
          ERR_print_errors(bio_err);
        }
        else {
          BIO_printf(bio_err,"Error Loading extension section %s\n",local_528);
        }
        goto LAB_0804fead;
      }
      x_00 = X509_new();
      if ((x_00 != (X509 *)0x0) &&
         ((local_530 == (char *)0x0 || (iVar33 = X509_set_version(x_00,2), iVar33 != 0)))) {
        if (local_54c == (ASN1_INTEGER *)0x0) {
          pAVar24 = X509_get_serialNumber(x_00);
          iVar33 = rand_serial(0,pAVar24);
        }
        else {
          iVar33 = X509_set_serialNumber(x_00,local_54c);
        }
        if ((((iVar33 != 0) &&
             (iVar33 = X509_set_issuer_name(x_00,x->req_info->subject), iVar33 != 0)) &&
            (pAVar23 = X509_gmtime_adj(x_00->cert_info->validity->notBefore,0),
            pAVar23 != (ASN1_TIME *)0x0)) &&
           (((pAVar23 = X509_time_adj_ex(x_00->cert_info->validity->notAfter,local_4f0,0,
                                         (time_t *)0x0), pAVar23 != (ASN1_TIME *)0x0 &&
             (iVar33 = X509_set_subject_name(x_00,x->req_info->subject), iVar33 != 0)) &&
            ((pEVar38 = X509_REQ_get_pubkey(x), pEVar38 != (EVP_PKEY *)0x0 &&
             (iVar33 = X509_set_pubkey(x_00,pEVar38), iVar33 != 0)))))) {
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
                goto LAB_0804e83d;
              }
              bVar40 = true;
              goto LAB_0804f21b;
            }
            ERR_print_errors(bio_err);
          }
          else {
            BIO_printf(bio_err,"Error Loading extension section %s\n",local_530);
          }
        }
      }
LAB_0804f0ee:
      pEVar38 = (EVP_PKEY *)0x0;
      goto LAB_0804e83d;
    }
    pcVar18 = "you need to specify a private key\n";
    goto LAB_080500ec;
  }
  pcVar14 = "Error getting passwords\n";
LAB_0804e81f:
  BIO_printf(bio_err,pcVar14);
LAB_0804e82d:
  pBVar15 = (BIO *)0x0;
  local_560 = (BIO *)0x0;
LAB_0804e837:
  pEVar38 = (EVP_PKEY *)0x0;
LAB_0804e839:
  x = (X509_REQ *)0x0;
  x_00 = (X509 *)0x0;
  goto LAB_0804e83d;
LAB_08050844:
  iVar33 = sk_num(local_500);
  if (iVar33 <= (int)local_538) goto LAB_08050178;
  pvVar28 = sk_value(local_500,(int)local_538);
  pcVar18 = *(char **)((int)pvVar28 + 4);
  iVar33 = OBJ_txt2nid(pcVar18);
  if (iVar33 != 0) {
    iVar29 = BIO_snprintf(local_484,100,"%s_default",pcVar18);
    if (99 < iVar29) goto LAB_08050786;
    pcVar32 = NCONF_get_string(req_conf,(char *)section,local_484);
    if (pcVar32 == (char *)0x0) {
      pcVar32 = "";
      ERR_clear_error();
    }
    BIO_snprintf(local_484,100,"%s_value",pcVar18);
    pFVar26 = (FILE *)NCONF_get_string(req_conf,(char *)section,local_484);
    if (pFVar26 == (FILE *)0x0) {
      ERR_clear_error();
    }
    BIO_snprintf(local_484,100,"%s_min",pcVar18);
    iVar29 = NCONF_get_number_e(req_conf,(char *)section,local_484,&local_4a4);
    if (iVar29 == 0) {
      ERR_clear_error();
      local_4a4 = -1;
    }
    BIO_snprintf(local_484,100,"%s_max",pcVar18);
    iVar29 = NCONF_get_number_e(req_conf,(char *)section,local_484,&local_4a0.flags);
    if (iVar29 == 0) {
      ERR_clear_error();
      local_4a0.flags = -1;
    }
    uVar17 = *(undefined4 *)((int)pvVar28 + 8);
    do {
      if (batch == 0) {
        BIO_printf(bio_err,"%s [%s]:",uVar17,pcVar32);
      }
      pcVar14 = (char *)0x0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      if (pFVar26 == (FILE *)0x0) {
        buf_16740[0] = '\0';
        if (batch == 0) {
          pcVar14 = (char *)stdin;
          pcVar18 = fgets(buf_16740,0x400,stdin);
          if (pcVar18 != (char *)0x0) goto LAB_08050a42;
          goto LAB_080500af;
        }
        buf_16740[0] = '\n';
        buf_16740[1] = '\0';
LAB_08050b73:
        if (*pcVar32 == '\0') goto LAB_0805088a;
        BUF_strlcpy(buf_16740,pcVar32,0x400);
        pcVar14 = (char *)0x400;
        BUF_strlcat(buf_16740,"\n",0x400);
      }
      else {
        BUF_strlcpy(buf_16740,(char *)pFVar26,0x400);
        BUF_strlcat(buf_16740,"\n",0x400);
        pcVar14 = (char *)pFVar26;
        BIO_printf(bio_err,"%s\n",pFVar26);
LAB_08050a42:
        if (buf_16740[0] == '\0') goto LAB_080500af;
        if (buf_16740[0] == '\n') goto LAB_08050b73;
        if ((buf_16740[0] == '.') && (buf_16740[1] == '\n')) goto LAB_0805088a;
      }
      puVar31 = (uint *)buf_16740;
      do {
        puVar30 = puVar31;
        uVar35 = *puVar30 + 0xfefefeff & ~*puVar30;
        uVar36 = uVar35 & 0x80808080;
        puVar31 = puVar30 + 1;
      } while (uVar36 == 0);
      bVar41 = (uVar35 & 0x8080) == 0;
      if (bVar41) {
        uVar36 = uVar36 >> 0x10;
      }
      if (bVar41) {
        puVar31 = (uint *)((int)puVar30 + 6);
      }
      iVar29 = (int)puVar31 + (-0x82fba04 - (uint)CARRY1((byte)uVar36,(byte)uVar36));
      if (buf_16740[iVar29] != '\n') goto LAB_080506d1;
      buf_16740[iVar29] = 0;
      iVar29 = req_check_len();
    } while (iVar29 == 0);
    iVar33 = X509_REQ_add1_attr_by_NID(x,iVar33,local_534,buf_16740,-1);
    if (iVar33 == 0) {
      BIO_printf(bio_err,"Error adding attribute\n");
      ERR_print_errors(bio_err);
      goto LAB_080500af;
    }
  }
LAB_0805088a:
  local_538 = (char *)((int)local_538 + 1);
  goto LAB_08050844;
LAB_08050786:
  pcVar14 = *(char **)((int)pvVar28 + 4);
  BIO_printf(bio_err,"Name \'%s\' too long\n",pcVar14);
  goto LAB_080500af;
LAB_080506d1:
  BIO_printf(bio_err,"weird input :-(\n",pcVar14);
LAB_080500af:
  if ((0 < local_51c) && (iVar33 = sk_num((_STACK *)x->req_info->attributes), iVar33 == 0)) {
    sk_free((_STACK *)x->req_info->attributes);
    x->req_info->attributes = (stack_st_X509_ATTRIBUTE *)0x0;
  }
  pcVar18 = "problems making Certificate Request\n";
LAB_080500ec:
  pEVar38 = (EVP_PKEY *)0x0;
  x_00 = (X509 *)0x0;
  BIO_printf(bio_err,pcVar18,pcVar14);
LAB_0804e83d:
  ERR_print_errors(bio_err);
  local_570 = 1;
LAB_0804e856:
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
}

