
/* WARNING: Type propagation algorithm not settling */

uint do_X509_REQ_sign(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined *puVar15;
  char *pcVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  byte *pbVar26;
  int iVar27;
  char *pcVar28;
  undefined4 *puVar29;
  byte bVar30;
  char **ppcVar31;
  int *piVar32;
  byte *pbVar33;
  char **ppcVar34;
  char *pcVar35;
  uint uVar36;
  undefined4 uVar37;
  int *piVar38;
  char *pcVar39;
  code *pcVar40;
  undefined4 uVar41;
  char *pcStack_5d8;
  int iStack_5d0;
  undefined4 *puStack_5c4;
  char *pcStack_5c0;
  char *pcStack_5bc;
  undefined4 *puStack_5b8;
  int iStack_5b4;
  int iStack_5ac;
  char *pcStack_5a8;
  char *pcStack_59c;
  char *pcStack_598;
  int iStack_594;
  char *pcStack_58c;
  char *pcStack_588;
  char *pcStack_580;
  char *pcStack_57c;
  char *pcStack_578;
  char *pcStack_574;
  int iStack_568;
  int iStack_564;
  char *pcStack_560;
  undefined4 uStack_55c;
  int iStack_54c;
  int iStack_548;
  char *pcStack_544;
  undefined4 uStack_540;
  char *pcStack_53c;
  char *pcStack_534;
  undefined4 uStack_530;
  undefined4 uStack_52c;
  int iStack_528;
  int iStack_524;
  int iStack_520;
  int iStack_51c;
  int iStack_518;
  int iStack_514;
  char *pcStack_510;
  undefined4 auStack_50c [7];
  undefined auStack_4f0 [99];
  char acStack_48d [1025];
  int iStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 *puStack_7c;
  undefined *puStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 local_40;
  undefined4 auStack_3c [6];
  int local_24;
  
  puStack_78 = PTR___stack_chk_guard_006aabf0;
  puStack_7c = auStack_3c;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_7c);
  local_40 = 0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_7c);
  puVar29 = &local_40;
  iVar17 = (*(code *)PTR_EVP_DigestSignInit_006a7f20)(puStack_7c,puVar29,param_4,0);
  if (iVar17 == 0) {
LAB_004242d8:
    uStack_88 = 0;
  }
  else {
    for (iVar17 = 0; iVar18 = (*(code *)PTR_sk_num_006a7f2c)(param_5), iVar17 < iVar18;
        iVar17 = iVar17 + 1) {
      param_3 = (*(code *)PTR_sk_value_006a7f24)(param_5,iVar17);
      iVar18 = (*(code *)PTR_pkey_ctrl_string_006a7f28)(local_40,param_3);
      if (iVar18 < 1) {
        puVar29 = (undefined4 *)0x634730;
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"parameter error \"%s\"\n",param_3);
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004242d8;
      }
    }
    puVar29 = puStack_7c;
    iVar17 = (*(code *)PTR_X509_REQ_sign_ctx_006a7f44)(param_2);
    uStack_88 = (uint)(0 < iVar17);
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(puStack_7c);
  if (local_24 == *(int *)puStack_78) {
    return uStack_88;
  }
  iVar17 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar15 = PTR___stack_chk_guard_006aabf0;
  puVar13 = PTR_bio_err_006a7f3c;
  uStack_84 = param_5;
  iStack_520 = -1;
  iStack_51c = -1;
  req_conf = 0;
  uStack_530 = 0;
  uStack_52c = 0;
  iStack_528 = 0;
  iStack_524 = 0;
  iStack_518 = 0;
  iStack_514 = 0;
  iStack_8c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_80 = param_3;
  uStack_74 = param_2;
  uStack_70 = param_1;
  iStack_568 = (*(code *)PTR_EVP_des_ede3_cbc_006a7f48)();
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  if (*(int *)puVar13 == 0) {
    uVar19 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar18 = (*(code *)PTR_BIO_new_006a7fa4)(uVar19);
    *(int *)puVar13 = iVar18;
    if (iVar18 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  uVar19 = *puVar29;
  iVar17 = iVar17 + -1;
  ppcVar31 = (char **)(puVar29 + 1);
  iStack_594 = 0x1001;
  if (iVar17 < 1) {
    uStack_55c = 0;
    pcStack_580 = (char *)0x0;
    pcVar39 = (char *)0x3;
    pcStack_5bc = (char *)0x0;
    piVar38 = (int *)0x3;
    uStack_540 = 3;
    pcStack_5c0 = (char *)0x0;
    pcStack_534 = (char *)0x0;
    bVar9 = false;
    iStack_5b4 = 0;
    pcStack_588 = (char *)0x0;
    pcStack_58c = (char *)0x0;
    pcStack_5d8 = (char *)0x0;
    pcStack_57c = (char *)0x0;
    pcStack_59c = (char *)0x0;
    pcStack_5a8 = (char *)0x0;
    pcStack_574 = (char *)0x0;
    pcStack_560 = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    pcStack_53c = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    pcStack_578 = (char *)0x0;
    pcStack_598 = (char *)0x0;
    puStack_5b8 = (undefined4 *)0x0;
    puStack_5c4 = (undefined4 *)0x0;
    pcStack_544 = (char *)0x0;
    iStack_548 = 0x1e;
    bVar5 = false;
    iStack_5d0 = 0;
    iStack_564 = 0;
    iStack_54c = 0;
  }
  else {
    iStack_564 = 0;
    iStack_54c = 0;
    uStack_55c = 0;
    uStack_540 = 3;
    pcStack_580 = (char *)0x0;
    pcVar39 = (char *)0x3;
    pcStack_5bc = (char *)0x0;
    piVar38 = (int *)0x3;
    iStack_548 = 0x1e;
    pcStack_5c0 = (char *)0x0;
    pcStack_534 = (char *)0x0;
    bVar9 = false;
    iStack_5b4 = 0;
    pcStack_588 = (char *)0x0;
    pcStack_58c = (char *)0x0;
    pcStack_5d8 = (char *)0x0;
    pcStack_57c = (char *)0x0;
    pcStack_59c = (char *)0x0;
    pcStack_5a8 = (char *)0x0;
    pcStack_574 = (char *)0x0;
    pcStack_560 = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    pcStack_53c = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    pcStack_578 = (char *)0x0;
    pcStack_598 = (char *)0x0;
    puStack_5b8 = (undefined4 *)0x0;
    puStack_5c4 = (undefined4 *)0x0;
    pcStack_544 = (char *)0x0;
    bVar5 = false;
    iStack_5d0 = 0;
LAB_004244b8:
    do {
      pcVar35 = *ppcVar31;
      iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-inform");
      iVar18 = iStack_564;
      if (iVar20 == 0) {
        iVar17 = iVar17 + -1;
        if (iVar17 != 0) {
          piVar38 = (int *)(*(code *)PTR_str2fmt_006a7f4c)(ppcVar31[1]);
          ppcVar34 = ppcVar31 + 1;
          goto LAB_004244ac;
        }
LAB_0042486c:
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"%s [options] <infile >outfile\n",uVar19);
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"where options  are\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -inform arg    input format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -outform arg   output format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -in arg        input file\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -out arg       output file\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -text          text form of request\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -pubkey        output public key\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -noout         do not output REQ\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -verify        verify signature on REQ\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -modulus       RSA modulus\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -nodes         don\'t encrypt the output key\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -engine e      use engine e, possibly a hardware device\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -subject       output the request\'s subject\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -passin        private key password source\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -key file      use the private key contained in file\n")
        ;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -keyform arg   key file format\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -keyout arg    file to send the key to\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -rand file%cfile%c...\n",0x3a,0x3a);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   "                load the file (or the files in the directory) into\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"                the random number generator\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -newkey rsa:bits generate a new RSA key of \'bits\' in size\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -newkey dsa:file generate a new DSA key, parameters taken from CA in \'file\'\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -newkey ec:file generate a new EC key, parameters taken from CA in \'file\'\n")
        ;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -[digest]      Digest to sign with (md5, sha1, md2, mdc2, md4)\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -config file   request template file.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -subj arg      set or modify request subject\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -multivalue-rdn enable support for multivalued RDNs\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -new           new request.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -batch         do not ask anything during request generation\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -x509          output a x509 structure instead of a cert. req.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -days          number of days a certificate generated by -x509 is valid for.\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -set_serial    serial number to use for a certificate generated by -x509.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -newhdr        output \"NEW\" in the header lines\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -asn1-kludge   Output the \'request\' in a format that is wrong but some CA\'s\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"                have been reported as requiring\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -extensions .. specify certificate extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -reqexts ..    specify request extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -utf8          input characters are UTF8 (default ASCII)\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -nameopt arg    - various certificate name options\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -reqopt arg    - various request text options\n\n");
        goto LAB_00424810;
      }
      iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-outform");
      if (iVar20 != 0) {
        iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-engine");
        if (iVar20 == 0) {
          iVar17 = iVar17 + -1;
          if (iVar17 == 0) goto LAB_0042486c;
          pcStack_5d8 = ppcVar31[1];
          ppcVar34 = ppcVar31 + 1;
        }
        else {
          iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-keygen_engine");
          if (iVar20 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_0042486c;
            iStack_5d0 = (*(code *)PTR_ENGINE_by_id_006a7f9c)(ppcVar31[1]);
            ppcVar34 = ppcVar31 + 1;
            if (iStack_5d0 == 0) {
              pcVar35 = ppcVar31[1];
              uVar19 = *(undefined4 *)puVar13;
              pcVar28 = "Can\'t find keygen engine %s\n";
              goto LAB_00424804;
            }
          }
          else {
            iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,&DAT_006330b4);
            if (iVar20 == 0) {
              iVar17 = iVar17 + -1;
              if (iVar17 == 0) goto LAB_0042486c;
              pcStack_5a8 = ppcVar31[1];
              ppcVar34 = ppcVar31 + 1;
            }
            else {
              iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-pubkey");
              ppcVar34 = ppcVar31;
              if (iVar20 == 0) {
                bVar11 = true;
              }
              else {
                iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,&DAT_006330c4);
                if (iVar20 == 0) {
                  pcStack_598 = (char *)0x1;
                }
                else {
                  iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-config");
                  if (iVar20 == 0) {
                    iVar17 = iVar17 + -1;
                    if (iVar17 == 0) goto LAB_0042486c;
                    pcStack_59c = ppcVar31[1];
                    ppcVar34 = ppcVar31 + 1;
                  }
                  else {
                    iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-keyform");
                    if (iVar20 == 0) {
                      iVar17 = iVar17 + -1;
                      if (iVar17 == 0) goto LAB_0042486c;
                      uStack_540 = (*(code *)PTR_str2fmt_006a7f4c)(ppcVar31[1]);
                      ppcVar34 = ppcVar31 + 1;
                    }
                    else if ((((*pcVar35 == '-') && (pcVar35[1] == 'i')) && (pcVar35[2] == 'n')) &&
                            (pcVar35[3] == '\0')) {
                      iVar17 = iVar17 + -1;
                      if (iVar17 == 0) goto LAB_0042486c;
                      pcStack_560 = ppcVar31[1];
                      ppcVar34 = ppcVar31 + 1;
                    }
                    else {
                      iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,&DAT_00632edc);
                      if (iVar20 == 0) {
                        iVar17 = iVar17 + -1;
                        if (iVar17 == 0) goto LAB_0042486c;
                        pcStack_574 = ppcVar31[1];
                        ppcVar34 = ppcVar31 + 1;
                      }
                      else {
                        iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-keyout");
                        if (iVar20 == 0) {
                          iVar17 = iVar17 + -1;
                          if (iVar17 == 0) goto LAB_0042486c;
                          pcStack_57c = ppcVar31[1];
                          ppcVar34 = ppcVar31 + 1;
                        }
                        else {
                          iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-passin");
                          if (iVar20 == 0) {
                            iVar17 = iVar17 + -1;
                            if (iVar17 == 0) goto LAB_0042486c;
                            pcStack_5c0 = ppcVar31[1];
                            ppcVar34 = ppcVar31 + 1;
                          }
                          else {
                            iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-passout");
                            if (iVar20 == 0) {
                              iVar17 = iVar17 + -1;
                              if (iVar17 == 0) goto LAB_0042486c;
                              pcStack_5bc = ppcVar31[1];
                              ppcVar34 = ppcVar31 + 1;
                            }
                            else {
                              iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-rand");
                              if (iVar20 == 0) {
                                iVar17 = iVar17 + -1;
                                if (iVar17 == 0) goto LAB_0042486c;
                                pcStack_534 = ppcVar31[1];
                                ppcVar34 = ppcVar31 + 1;
                              }
                              else {
                                iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-newkey");
                                if (iVar20 != 0) {
                                  iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-pkeyopt");
                                  if (iVar20 == 0) {
                                    if (iVar17 != 1) {
                                      puVar29 = puStack_5c4;
                                      pcVar40 = (code *)PTR_sk_push_006a80a8;
                                      if (puStack_5c4 == (undefined4 *)0x0) {
                                        puVar29 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a80a4)();
                                        puStack_5c4 = puVar29;
                                        pcVar40 = (code *)PTR_sk_push_006a80a8;
joined_r0x00427474:
                                        PTR_sk_push_006a80a8 = pcVar40;
                                        if (puVar29 == (undefined4 *)0x0) goto LAB_0042486c;
                                      }
LAB_004273f0:
                                      iVar20 = (*pcVar40)(puVar29,ppcVar31[1]);
joined_r0x004277bc:
                                      iVar17 = iVar17 + -1;
                                      ppcVar34 = ppcVar31 + 1;
                                      if (iVar20 != 0) goto LAB_004244ac;
                                    }
                                  }
                                  else {
                                    iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-sigopt");
                                    if (iVar20 != 0) {
                                      iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-batch");
                                      if (iVar20 == 0) {
                                        batch = 1;
                                      }
                                      else {
                                        iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-newhdr");
                                        if (iVar20 == 0) {
                                          bVar12 = true;
                                        }
                                        else {
                                          iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                             (pcVar35,"-modulus");
                                          if (iVar20 == 0) {
                                            bVar9 = true;
                                          }
                                          else {
                                            iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                               (pcVar35,"-verify");
                                            if (iVar20 == 0) {
                                              bVar6 = true;
                                            }
                                            else {
                                              iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                 (pcVar35,"-nodes");
                                              if (iVar20 == 0) {
                                                pcStack_53c = (char *)0x1;
                                              }
                                              else {
                                                iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                   (pcVar35,"-noout");
                                                if (iVar20 == 0) {
                                                  bVar7 = true;
                                                }
                                                else {
                                                  iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                     (pcVar35,"-verbose");
                                                  if (iVar20 == 0) {
                                                    pcStack_578 = (char *)0x1;
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-utf8");
                                                    if (iVar20 != 0) {
                                                      iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar35,"-nameopt");
                                                      if (iVar20 == 0) {
                                                        if (iVar17 != 1) {
                                                          puVar29 = &uStack_530;
                                                          pcVar40 = (code *)PTR_set_name_ex_006a80ac
                                                          ;
                                                          goto LAB_004273f0;
                                                        }
                                                      }
                                                      else {
                                                        iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar35,"-reqopt");
                                                        if (iVar20 != 0) {
                                                          iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                             (pcVar35,"-subject");
                                                          if (iVar20 == 0) {
                                                            bVar10 = true;
                                                          }
                                                          else {
                                                            iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                               (pcVar35,"-text");
                                                            if (iVar20 == 0) {
                                                              bVar8 = true;
                                                            }
                                                            else {
                                                              iVar20 = (*(code *)PTR_strcmp_006aac20
                                                                       )(pcVar35,"-x509");
                                                              if (iVar20 == 0) {
                                                                bVar5 = true;
                                                              }
                                                              else {
                                                                iVar20 = (*(code *)
                                                  PTR_strcmp_006aac20)(pcVar35,"-asn1-kludge");
                                                  if (iVar20 == 0) {
                                                    bVar4 = true;
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-no-asn1-kludge");
                                                    if (iVar20 == 0) {
                                                      bVar4 = false;
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar35,"-subj");
                                                      if (iVar20 == 0) {
                                                        iVar17 = iVar17 + -1;
                                                        if (iVar17 == 0) goto LAB_0042486c;
                                                        pcStack_580 = ppcVar31[1];
                                                        ppcVar34 = ppcVar31 + 1;
                                                      }
                                                      else {
                                                        iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar35,
                                                  "-multivalue-rdn");
                                                  if (iVar20 == 0) {
                                                    uStack_55c = 1;
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-days");
                                                    if (iVar20 == 0) {
                                                      iVar17 = iVar17 + -1;
                                                      if (iVar17 == 0) goto LAB_0042486c;
                                                      ppcVar34 = ppcVar31 + 1;
                                                      iVar20 = (*(code *)PTR_strtol_006aaa68)
                                                                         (ppcVar31[1],0,10);
                                                      iStack_548 = 0x1e;
                                                      if (iVar20 != 0) {
                                                        iStack_548 = iVar20;
                                                      }
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar35,"-set_serial");
                                                      if (iVar20 == 0) {
                                                        if (iVar17 == 1) goto LAB_0042486c;
                                                        iStack_5b4 = (*(code *)
                                                  PTR_s2i_ASN1_INTEGER_006a80b4)(0,ppcVar31[1]);
                                                  iVar20 = iStack_5b4;
                                                  goto joined_r0x004277bc;
                                                  }
                                                  iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                     (pcVar35,"-extensions");
                                                  if (iVar20 == 0) {
                                                    iVar17 = iVar17 + -1;
                                                    if (iVar17 == 0) goto LAB_0042486c;
                                                    pcStack_58c = ppcVar31[1];
                                                    ppcVar34 = ppcVar31 + 1;
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-reqexts");
                                                    if (iVar20 == 0) {
                                                      iVar17 = iVar17 + -1;
                                                      if (iVar17 == 0) goto LAB_0042486c;
                                                      pcStack_588 = ppcVar31[1];
                                                      ppcVar34 = ppcVar31 + 1;
                                                    }
                                                    else {
                                                      iStack_54c = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a802c)(pcVar35 + 1);
                                                  iVar18 = iStack_54c;
                                                  if (iStack_54c == 0) {
                                                    (*(code *)PTR_BIO_printf_006a7f38)
                                                              (*(undefined4 *)puVar13,
                                                               "unknown option %s\n",*ppcVar31);
                                                    goto LAB_0042486c;
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
                                                  goto LAB_004244ac;
                                                  }
                                                  if (iVar17 != 1) {
                                                    puVar29 = &uStack_52c;
                                                    pcVar40 = (code *)PTR_set_cert_ex_006a80b0;
                                                    goto LAB_004273f0;
                                                  }
                                                  }
                                                  goto LAB_0042486c;
                                                  }
                                                  iStack_594 = 0x1000;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      goto LAB_004244ac;
                                    }
                                    if (iVar17 != 1) {
                                      puVar29 = puStack_5b8;
                                      pcVar40 = (code *)PTR_sk_push_006a80a8;
                                      if (puStack_5b8 == (undefined4 *)0x0) {
                                        puVar29 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a80a4)();
                                        puStack_5b8 = puVar29;
                                        pcVar40 = (code *)PTR_sk_push_006a80a8;
                                        goto joined_r0x00427474;
                                      }
                                      goto LAB_004273f0;
                                    }
                                  }
                                  goto LAB_0042486c;
                                }
                                iVar17 = iVar17 + -1;
                                if (iVar17 == 0) goto LAB_0042486c;
                                pcStack_544 = ppcVar31[1];
                                pcStack_598 = (char *)0x1;
                                ppcVar34 = ppcVar31 + 1;
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
LAB_004244ac:
        iStack_564 = iVar18;
        iVar17 = iVar17 + -1;
        ppcVar31 = ppcVar34 + 1;
        if (iVar17 == 0) break;
        goto LAB_004244b8;
      }
      if (iVar17 == 1) goto LAB_0042486c;
      ppcVar34 = ppcVar31 + 1;
      iVar17 = iVar17 + -2;
      ppcVar31 = ppcVar31 + 2;
      pcVar39 = (char *)(*(code *)PTR_str2fmt_006a7f4c)(*ppcVar34);
    } while (iVar17 != 0);
  }
  puVar14 = PTR_bio_err_006a7f3c;
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  iVar17 = (*(code *)PTR_app_passwd_006a7f54)
                     (*(undefined4 *)puVar13,pcStack_5c0,pcStack_5bc,&iStack_518,&iStack_514);
  if (iVar17 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar14,"Error getting passwords\n");
  }
  else {
    if (pcStack_59c == (char *)0x0) {
      req_conf = *(int *)PTR_config_006a7f68;
      if (req_conf == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar14,"Unable to load config info from %s\n",
                   *(undefined4 *)PTR_default_config_file_006a7fdc);
        if (pcStack_598 != (char *)0x0) {
          iVar18 = 0;
          iVar17 = 0;
          goto LAB_004245d0;
        }
LAB_004245a4:
        if (req_conf != 0) goto LAB_004245b8;
LAB_00424e24:
        iVar17 = (*(code *)PTR_add_oid_section_006a7f60)(*(undefined4 *)puVar13,req_conf);
        if (iVar17 != 0) {
          if (iStack_54c == 0) {
            iVar17 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,&DAT_00632464,"default_md");
            if (iVar17 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar17 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(iVar17);
              if (iVar17 != 0) {
                iStack_564 = iVar17;
              }
            }
          }
          if ((pcStack_58c == (char *)0x0) &&
             (pcStack_58c = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                              (req_conf,&DAT_00632464,"x509_extensions"),
             pcStack_58c == (char *)0x0)) {
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
LAB_00424eb4:
            piVar32 = (int *)0x630000;
            if ((iStack_518 == 0) &&
               (iStack_518 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                       (req_conf,&DAT_00632464,"input_password"), iStack_518 == 0))
            {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            if ((iStack_514 == 0) &&
               (iStack_514 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                       (req_conf,&DAT_00632464,"output_password"), iStack_514 == 0))
            {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                        (req_conf,&DAT_00632464,"string_mask");
            if (pcVar35 == (char *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar17 = (*(code *)PTR_ASN1_STRING_set_default_mask_asc_006a7fc0)(pcVar35);
              if (iVar17 == 0) {
                uVar19 = *(undefined4 *)puVar13;
                pcVar28 = "Invalid global string mask setting %s\n";
                goto LAB_00424804;
              }
            }
            if (iStack_594 == 0x1000) {
LAB_00424f6c:
              iStack_594 = 0x1000;
            }
            else {
              pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                          (req_conf,&DAT_00632464,&DAT_00633b60);
              if (pcVar35 == (char *)0x0) {
                (*(code *)PTR_ERR_clear_error_006a7fe0)();
              }
              else if ((((*pcVar35 == 'y') && (pcVar35[1] == 'e')) && (pcVar35[2] == 's')) &&
                      (pcVar35[3] == '\0')) goto LAB_00424f6c;
            }
            if ((pcStack_588 == (char *)0x0) &&
               (pcStack_588 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                (req_conf,&DAT_00632464,"req_extensions"),
               pcStack_588 == (char *)0x0)) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_50c,0,0,0,0,1);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_50c,req_conf);
              iVar17 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                 (req_conf,auStack_50c,pcStack_588,0);
              if (iVar17 == 0) {
                uVar19 = *(undefined4 *)puVar13;
                pcVar28 = "Error Loading request extension section %s\n";
                pcVar35 = pcStack_588;
                goto LAB_00424804;
              }
            }
            uVar19 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            iVar17 = (*(code *)PTR_BIO_new_006a7fa4)(uVar19);
            uVar19 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            iVar18 = (*(code *)PTR_BIO_new_006a7fa4)(uVar19);
            if ((iVar17 != 0) && (iVar18 != 0)) {
              uVar19 = (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar13,pcStack_5d8,0);
              if (pcStack_5a8 == (char *)0x0) goto LAB_004250cc;
              iStack_524 = (*(code *)PTR_load_key_006a7fc8)
                                     (*(undefined4 *)PTR_bio_err_006a7f3c,pcStack_5a8,uStack_540,0,
                                      iStack_518,uVar19,"Private Key");
              if (iStack_524 != 0) {
                iVar20 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,&DAT_00632464,"RANDFILE")
                ;
                if (iVar20 == 0) goto LAB_00425c50;
                goto LAB_004250b4;
              }
            }
            goto LAB_004245d0;
          }
          (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_50c,0,0,0,0,1);
          (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_50c,req_conf);
          iVar17 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)(req_conf,auStack_50c,pcStack_58c,0);
          if (iVar17 != 0) goto LAB_00424eb4;
          uVar19 = *(undefined4 *)puVar13;
          pcVar28 = "Error Loading extension section %s\n";
          pcVar35 = pcStack_58c;
LAB_00424804:
          (*(code *)PTR_BIO_printf_006a7f38)(uVar19,pcVar28,pcVar35);
          goto LAB_00424810;
        }
      }
      else {
        if (pcStack_578 != (char *)0x0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar14,"Using configuration from %s\n",
                     *(undefined4 *)PTR_default_config_file_006a7fdc);
          goto LAB_004245a4;
        }
LAB_004245b8:
        iVar17 = (*(code *)PTR_load_config_006a7f64)(*(undefined4 *)puVar13);
        if (iVar17 != 0) {
          iVar17 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,0,"oid_file");
          if (iVar17 == 0) {
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
          }
          else {
            iVar17 = (*(code *)PTR_BIO_new_file_006a7fac)(iVar17,"r");
            if (iVar17 != 0) {
              (*(code *)PTR_OBJ_create_objects_006a7fb0)(iVar17);
              (*(code *)PTR_BIO_free_006a7f70)(iVar17);
            }
          }
          goto LAB_00424e24;
        }
      }
      iVar18 = 0;
      iVar17 = 0;
      goto LAB_004245d0;
    }
    auStack_50c[0] = 0xffffffff;
    if (pcStack_578 != (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar14,"Using configuration from %s\n",pcStack_59c);
    }
    req_conf = (*(code *)PTR_NCONF_new_006a7f58)(0);
    iVar17 = (*(code *)PTR_NCONF_load_006a7f5c)(req_conf,pcStack_59c,auStack_50c);
    if (iVar17 != 0) goto LAB_004245a4;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar13,"error on line %ld of %s\n",auStack_50c[0],pcStack_59c);
  }
LAB_00424810:
  iVar18 = 0;
  iVar17 = 0;
LAB_004245d0:
  iVar20 = 0;
LAB_004245d8:
  piVar38 = (int *)0x0;
  piVar32 = (int *)0x0;
LAB_004245dc:
  uVar36 = 1;
  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
  do {
    if ((req_conf != 0) && (req_conf != *(int *)PTR_config_006a7f68)) {
      (*(code *)PTR_NCONF_free_006a7f6c)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(iVar17);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar18);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(iStack_524);
    if (iVar20 != 0) {
      (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar20);
    }
    if (puStack_5c4 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)(puStack_5c4);
    }
    if (puStack_5b8 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)(puStack_5b8);
    }
    if (iStack_5d0 != 0) {
      (*(code *)PTR_ENGINE_free_006a7f84)(iStack_5d0);
    }
    if (iStack_528 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_X509_REQ_free_006a7f8c)(piVar38);
    (*(code *)PTR_X509_free_006a7f90)(piVar32);
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iStack_5b4);
    if ((pcStack_5c0 != (char *)0x0) && (iStack_518 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if ((pcStack_5bc != (char *)0x0) && (iStack_514 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_OBJ_cleanup_006a7f98)();
    if (iStack_8c == *(int *)puVar15) {
      return uVar36;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00425c50:
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
LAB_004250b4:
    (*(code *)PTR_app_RAND_load_file_006a7fcc)(iVar20,*(undefined4 *)puVar13,0);
LAB_004250cc:
    if (pcStack_598 != (char *)0x0) {
      if (iStack_524 == 0) {
        iVar21 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,piVar32 + 0x919,"RANDFILE");
        if (iVar21 == 0) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        (*(code *)PTR_app_RAND_load_file_006a7fcc)(iVar21,*(undefined4 *)puVar13,0);
        if (pcStack_534 != (char *)0x0) {
          (*(code *)PTR_app_RAND_load_files_006a8038)(pcStack_534);
        }
        if (pcStack_544 == (char *)0x0) {
          iVar20 = 0;
        }
        else {
          iVar20 = set_keygen_ctx(*(undefined4 *)puVar13,pcStack_544,&iStack_520,&iStack_51c,
                                  &iStack_528,iStack_5d0);
          if (iVar20 == 0) goto LAB_004245d8;
        }
        if ((iStack_51c < 1) &&
           (iVar22 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                               (req_conf,piVar32 + 0x919,"default_bits",&iStack_51c), iVar22 == 0))
        {
          iStack_51c = 0x200;
        }
        else if ((iStack_51c < 0x180) && ((iStack_520 == 6 || (iStack_520 == 0x74)))) {
          piVar38 = (int *)0x0;
          piVar32 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"private key length is too short,\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"it needs to be at least %d bits, not %ld\n",0x180,
                     iStack_51c);
          goto LAB_004245dc;
        }
        if ((iVar20 == 0) &&
           (iVar20 = set_keygen_ctx(*(undefined4 *)puVar13,0,&iStack_520,&iStack_51c,&iStack_528,
                                    iStack_5d0), iVar20 == 0)) goto LAB_004245d8;
        iVar22 = 0;
        if (puStack_5c4 != (undefined4 *)0x0) {
          for (; iVar23 = (*(code *)PTR_sk_num_006a7f2c)(puStack_5c4), iVar22 < iVar23;
              iVar22 = iVar22 + 1) {
            uVar19 = (*(code *)PTR_sk_value_006a7f24)(puStack_5c4,iVar22);
            iVar23 = (*(code *)PTR_pkey_ctrl_string_006a7f28)(iVar20,uVar19);
            if (iVar23 < 1) {
              piVar38 = (int *)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar13,"parameter error \"%s\"\n",uVar19);
              piVar32 = (int *)0x0;
              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
              goto LAB_004245dc;
            }
          }
        }
        puVar14 = PTR_bio_err_006a7f3c;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"Generating a %ld bit %s private key\n",iStack_51c,
                   iStack_528);
        (*(code *)PTR_EVP_PKEY_CTX_set_cb_006a8040)(iVar20,genpkey_cb);
        (*(code *)PTR_EVP_PKEY_CTX_set_app_data_006a8044)(iVar20,*(undefined4 *)puVar13);
        iVar22 = (*(code *)PTR_EVP_PKEY_keygen_006a8048)(iVar20,&iStack_524);
        if (iVar22 < 1) {
          piVar32 = (int *)0x0;
          piVar38 = (int *)0x0;
          (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar14,"Error Generating Key\n");
          goto LAB_004245dc;
        }
        (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar20);
        (*(code *)PTR_app_RAND_write_file_006a804c)(iVar21,*(undefined4 *)puVar14);
        if ((pcStack_57c == (char *)0x0) &&
           (pcStack_57c = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                            (req_conf,piVar32 + 0x919,"default_keyfile"),
           pcStack_57c == (char *)0x0)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar14,"writing new private key to stdout\n");
          (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"writing new private key to \'%s\'\n",pcStack_57c);
          iVar20 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6c,5,pcStack_57c);
          pcVar35 = pcStack_57c;
          if (iVar20 < 1) goto LAB_00426268;
        }
        pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                    (req_conf,piVar32 + 0x919,"encrypt_rsa_key");
        if (pcVar35 == (char *)0x0) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
          pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                      (req_conf,piVar32 + 0x919,"encrypt_key");
          if (pcVar35 != (char *)0x0) goto LAB_00426170;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        else {
LAB_00426170:
          if (((*pcVar35 == 'n') && (pcVar35[1] == 'o')) && (pcVar35[2] == '\0')) {
            iStack_568 = 0;
          }
        }
        iVar20 = 4;
        if (pcStack_53c != (char *)0x0) {
          iStack_568 = 0;
        }
        while (iVar21 = (*(code *)PTR_PEM_write_bio_PrivateKey_006a8050)
                                  (iVar18,iStack_524,iStack_568,0,0,0,iStack_514), iVar21 == 0) {
          uVar36 = (*(code *)PTR_ERR_peek_error_006a8054)();
          if (((uVar36 & 0xfff) != 0x6d) || (iVar20 = iVar20 + -1, iVar20 == 0)) goto LAB_004245d0;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"-----\n");
        if (iStack_524 == 0) {
LAB_00425644:
          iVar20 = 0;
          piVar32 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"you need to specify a private key\n");
          goto LAB_004245dc;
        }
      }
      piVar38 = (int *)(*(code *)PTR_X509_REQ_new_006a7fd0)();
      iVar20 = iStack_524;
      if (piVar38 != (int *)0x0) {
        iStack_568 = iStack_524;
        pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                    (req_conf,piVar32 + 0x919,"prompt");
        if (pcVar35 == (char *)0x0) {
          bVar2 = false;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        else {
          bVar2 = *pcVar35 == 'n';
          if ((*pcVar35 == 'n') && (bVar2 = pcVar35[1] == 'o', pcVar35[1] == 'o')) {
            bVar2 = pcVar35[2] == '\0';
          }
        }
        iVar21 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                           (req_conf,piVar32 + 0x919,"distinguished_name");
        pcVar35 = pcVar39;
        if (iVar21 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"unable to find \'%s\' in config\n","distinguished_name"
                    );
        }
        else {
          iVar22 = (*(code *)PTR_NCONF_get_section_006a7fd4)(req_conf,iVar21);
          if (iVar22 == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar21);
          }
          else {
            iVar23 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,piVar32 + 0x919,"attributes")
            ;
            if (iVar23 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
              pcStack_59c = (char *)0x0;
            }
            else {
              pcStack_59c = (char *)(*(code *)PTR_NCONF_get_section_006a7fd4)(req_conf,iVar23);
              if (pcStack_59c == (char *)0x0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar23);
                goto LAB_00425224;
              }
            }
            iVar24 = (*(code *)PTR_X509_REQ_set_version_006a7fd8)(piVar38,0);
            if (iVar24 != 0) {
              if (bVar2) {
                uVar19 = *(undefined4 *)(*piVar38 + 0x10);
                for (iVar21 = 0; iVar23 = (*(code *)PTR_sk_num_006a7f2c)(iVar22), iVar21 < iVar23;
                    iVar21 = iVar21 + 1) {
                  iVar23 = (*(code *)PTR_sk_value_006a7f24)(iVar22,iVar21);
                  pbVar26 = *(byte **)(iVar23 + 4);
                  bVar30 = *pbVar26;
                  pbVar33 = pbVar26;
                  while (bVar30 != 0) {
                    if ((bVar30 == 0x3a) || ((bVar30 & 0xfd) == 0x2c)) {
                      bVar30 = pbVar33[1];
                      if (bVar30 != 0) {
                        pbVar26 = pbVar33 + 1;
                      }
                      break;
                    }
                    pbVar33 = pbVar33 + 1;
                    bVar30 = *pbVar33;
                  }
                  iVar23 = (*(code *)PTR_X509_NAME_add_entry_by_txt_006a8070)
                                     (uVar19,pbVar26,iStack_594,*(undefined4 *)(iVar23 + 8),
                                      0xffffffff,0xffffffff,-(uint)(bVar30 == 0x2b));
                  if (iVar23 == 0) goto LAB_00425224;
                }
                iVar21 = (*(code *)PTR_X509_NAME_entry_count_006a8074)(uVar19);
                if (iVar21 != 0) {
                  if (!bVar5) {
                    for (iVar21 = 0; iVar22 = (*(code *)PTR_sk_num_006a7f2c)(pcStack_59c),
                        iVar21 < iVar22; iVar21 = iVar21 + 1) {
                      iVar22 = (*(code *)PTR_sk_value_006a7f24)(pcStack_59c,iVar21);
                      iVar22 = (*(code *)PTR_X509_REQ_add1_attr_by_txt_006a8078)
                                         (piVar38,*(undefined4 *)(iVar22 + 4),iStack_594,
                                          *(undefined4 *)(iVar22 + 8),0xffffffff);
                      if (iVar22 == 0) goto LAB_00425224;
                    }
                  }
                  goto LAB_00425d70;
                }
LAB_00426a70:
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"error, no objects specified in config file\n");
                pcVar35 = pcVar39;
              }
              else if (pcStack_580 == (char *)0x0) {
                pcStack_598 = *(char **)(*piVar38 + 0x10);
                if (batch == 0) {
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "You are about to be asked to enter information that will be incorporated\n"
                            );
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,"into your certificate request.\n");
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "What you are about to enter is what is called a Distinguished Name or a DN.\n"
                            );
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "There are quite a few fields but you can leave some blank\n");
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "For some fields there will be a default value,\n");
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "If you enter \'.\', the field will be left blank.\n");
                  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"-----\n");
                }
                iVar24 = (*(code *)PTR_sk_num_006a7f2c)(iVar22);
                if (iVar24 != 0) {
                  pcStack_580 = (char *)0xffffffff;
                  pcStack_544 = "_max";
                  pcStack_53c = "%s [%s]:";
                  pcStack_578 = "\n";
LAB_00426470:
                  pcStack_580 = pcStack_580 + 1;
                  iVar24 = (*(code *)PTR_sk_num_006a7f2c)(iVar22);
                  pcStack_534 = pcVar39;
                  if ((int)pcStack_580 < iVar24) {
                    iVar24 = (*(code *)PTR_sk_value_006a7f24)(iVar22,pcStack_580);
                    pbVar33 = *(byte **)(iVar24 + 4);
                    iVar25 = check_end(pbVar33,&DAT_00633f14);
                    if ((((iVar25 != 0) && (iVar25 = check_end(pbVar33,&DAT_00633f1c), iVar25 != 0))
                        && (iVar25 = check_end(pbVar33,"_default"), iVar25 != 0)) &&
                       (iVar25 = check_end(pbVar33,"_value"), iVar25 != 0)) {
                      bVar30 = *pbVar33;
                      if (bVar30 == 0) {
LAB_00426580:
                        uVar19 = 0;
                      }
                      else if ((bVar30 == 0x3a) || (pbVar26 = pbVar33, (bVar30 & 0xfd) == 0x2c)) {
                        pbVar26 = pbVar33;
                        bVar1 = pbVar33[1];
                        if (pbVar33[1] != 0) goto LAB_0042656c;
                        uVar19 = 0;
                      }
                      else {
                        do {
                          pbVar3 = pbVar26;
                          pbVar26 = pbVar3 + 1;
                          bVar1 = *pbVar26;
                          if (bVar1 == 0) goto LAB_00426574;
                        } while ((bVar1 != 0x3a) && ((bVar1 & 0xfd) != 0x2c));
                        bVar1 = pbVar3[2];
                        if (bVar1 != 0) {
LAB_0042656c:
                          bVar30 = bVar1;
                          pbVar33 = pbVar26 + 1;
                        }
LAB_00426574:
                        if (bVar30 != 0x2b) goto LAB_00426580;
                        pbVar33 = pbVar33 + 1;
                        uVar19 = 0xffffffff;
                      }
                      iVar25 = (*(code *)PTR_OBJ_txt2nid_006a805c)(pbVar33);
                      if (iVar25 != 0) {
                        iVar27 = (*(code *)PTR_BIO_snprintf_006a8060)
                                           (auStack_4f0,100,"%s_default",*(undefined4 *)(iVar24 + 4)
                                           );
                        if (99 < iVar27) {
                          uVar19 = *(undefined4 *)(iVar24 + 4);
                          goto LAB_00426944;
                        }
                        pcVar28 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                    (req_conf,iVar21,auStack_4f0);
                        if (pcVar28 == (char *)0x0) {
                          pcVar28 = "";
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)
                                  (auStack_4f0,100,"%s_value",*(undefined4 *)(iVar24 + 4));
                        pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                    (req_conf,iVar21,auStack_4f0);
                        if (pcVar35 == (char *)0x0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)
                                  (auStack_4f0,100,"%s_min",*(undefined4 *)(iVar24 + 4));
                        iVar27 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar21,auStack_4f0,&pcStack_510);
                        if (iVar27 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          pcStack_510 = (char *)0xffffffff;
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)
                                  (auStack_4f0,100,"%s_max",*(undefined4 *)(iVar24 + 4));
                        iVar27 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar21,auStack_4f0,auStack_50c);
                        if (iVar27 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          auStack_50c[0] = 0xffffffff;
                        }
                        uVar41 = auStack_50c[0];
                        pcVar16 = pcStack_510;
                        uVar37 = *(undefined4 *)(iVar24 + 8);
                        uStack_55c = 0x630000;
                        pcStack_560 = pcStack_510;
                        do {
                          if (batch == 0) {
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)puVar13,"%s [%s]:",uVar37,pcVar28);
                          }
                          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar13,0xb,0,0);
                          if (pcVar35 == (char *)0x0) {
                            acStack_48d[1] = '\0';
                            if (batch == 0) {
                              iVar24 = (*(code *)PTR_fgets_006aabe8)
                                                 (acStack_48d + 1,0x400,
                                                  *(undefined4 *)PTR_stdin_006aab20);
                              if (iVar24 != 0) goto LAB_004267ac;
                              goto LAB_00425224;
                            }
                            acStack_48d[2] = '\0';
                            acStack_48d[1] = '\n';
LAB_00426a1c:
                            if (*pcVar28 == '\0') goto LAB_00426470;
                            (*(code *)PTR_BUF_strlcpy_006a8064)(acStack_48d + 1,pcVar28,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(acStack_48d + 1,"\n",0x400);
                          }
                          else {
                            (*(code *)PTR_BUF_strlcpy_006a8064)(acStack_48d + 1,pcVar35,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(acStack_48d + 1,"\n",0x400);
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)PTR_bio_err_006a7f3c,"%s\n",pcVar35);
LAB_004267ac:
                            if (acStack_48d[1] == '\0') goto LAB_00425224;
                            if (acStack_48d[1] == '\n') goto LAB_00426a1c;
                            if ((acStack_48d[1] == '.') && (acStack_48d[2] == '\n'))
                            goto LAB_00426470;
                          }
                          iVar24 = (*(code *)PTR_strlen_006aab30)(acStack_48d + 1);
                          if (acStack_48d[iVar24] != '\n') goto LAB_00426a94;
                          acStack_48d[iVar24] = '\0';
                          iVar24 = req_check_len(iVar24 + -1,pcVar16,uVar41);
                        } while (iVar24 == 0);
                        iVar24 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a806c)
                                           (pcStack_598,iVar25,iStack_594,acStack_48d + 1,0xffffffff
                                            ,0xffffffff,uVar19);
                        if (iVar24 == 0) goto LAB_00425224;
                      }
                    }
                    goto LAB_00426470;
                  }
                  iVar21 = (*(code *)PTR_X509_NAME_entry_count_006a8074)(pcStack_598);
                  if (iVar21 == 0) goto LAB_00426a70;
                  if ((!bVar5) && (pcStack_59c != (char *)0x0)) {
                    iVar21 = (*(code *)PTR_sk_num_006a7f2c)(pcStack_59c);
                    if ((0 < iVar21) && (batch == 0)) {
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar13,
                                 "\nPlease enter the following \'extra\' attributes\n");
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar13,"to be sent with your certificate request\n"
                                );
                    }
                    iStack_5ac = 0;
                    pcStack_560 = (char *)0x630000;
                    pcStack_598 = "\n";
                    pcStack_544 = "%s\n";
LAB_00426ba4:
                    uStack_55c = 0x630000;
                    iVar21 = (*(code *)PTR_sk_num_006a7f2c)(pcStack_59c);
                    if (iStack_5ac < iVar21) {
                      iVar21 = (*(code *)PTR_sk_value_006a7f24)(pcStack_59c,iStack_5ac);
                      uVar19 = *(undefined4 *)(iVar21 + 4);
                      pcVar35 = (char *)(*(code *)PTR_OBJ_txt2nid_006a805c)(uVar19);
                      if (pcVar35 == (char *)0x0) goto LAB_00426bfc;
                      iVar22 = (*(code *)PTR_BIO_snprintf_006a8060)
                                         (auStack_4f0,100,"%s_default",uVar19);
                      if (iVar22 < 100) {
                        pcVar28 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                    (req_conf,iVar23,auStack_4f0);
                        if (pcVar28 == (char *)0x0) {
                          pcVar28 = "";
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_4f0,100,"%s_value",uVar19);
                        iVar22 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                           (req_conf,iVar23,auStack_4f0);
                        if (iVar22 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_4f0,100,"%s_min",uVar19);
                        iVar24 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar23,auStack_4f0,&pcStack_510);
                        if (iVar24 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          pcStack_510 = (char *)0xffffffff;
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_4f0,100,"%s_max",uVar19);
                        iVar24 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar23,auStack_4f0,auStack_50c);
                        if (iVar24 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          auStack_50c[0] = 0xffffffff;
                        }
                        uVar19 = auStack_50c[0];
                        pcVar16 = pcStack_510;
                        puVar14 = PTR_bio_err_006a7f3c;
                        uVar41 = *(undefined4 *)(iVar21 + 8);
                        pcStack_580 = pcStack_510;
                        pcStack_578 = PTR_bio_err_006a7f3c;
                        do {
                          if (batch == 0) {
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)puVar13,"%s [%s]:",uVar41,pcVar28);
                          }
                          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar13,0xb,0,0);
                          if (iVar22 == 0) {
                            buf_16713[0] = '\0';
                            if (batch == 0) {
                              iVar21 = (*(code *)PTR_fgets_006aabe8)
                                                 (buf_16713,0x400,*(undefined4 *)PTR_stdin_006aab20)
                              ;
                              if (iVar21 != 0) goto LAB_00426e38;
                              goto LAB_00426fac;
                            }
                            buf_16713[0] = '\n';
                            buf_16713[1] = '\0';
LAB_00426f4c:
                            if (*pcVar28 == '\0') goto LAB_00426bfc;
                            (*(code *)PTR_BUF_strlcpy_006a8064)(buf_16713,pcVar28,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(buf_16713,"\n",0x400);
                          }
                          else {
                            (*(code *)PTR_BUF_strlcpy_006a8064)(buf_16713,iVar22,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(buf_16713,"\n",0x400);
                            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar14,"%s\n",iVar22)
                            ;
LAB_00426e38:
                            if (buf_16713[0] == '\0') {
LAB_00426fac:
                              uStack_55c = 0x630000;
                              goto LAB_00425224;
                            }
                            if (buf_16713[0] == '\n') goto LAB_00426f4c;
                            if ((buf_16713[0] == '.') && (buf_16713[1] == '\n')) goto LAB_00426bfc;
                          }
                          uStack_55c = 0x630000;
                          iVar21 = (*(code *)PTR_strlen_006aab30)(buf_16713);
                          if ((&DAT_006aad1f)[iVar21] != '\n') goto LAB_00426a94;
                          (&DAT_006aad1f)[iVar21] = '\0';
                          iVar21 = req_check_len(iVar21 + -1,pcVar16,uVar19);
                        } while (iVar21 == 0);
                        iVar21 = (*(code *)PTR_X509_REQ_add1_attr_by_NID_006a807c)
                                           (piVar38,pcVar35,iStack_594,buf_16713,0xffffffff);
                        if (iVar21 != 0) goto LAB_00426bfc;
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar13,"Error adding attribute\n");
                        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
                      }
                      else {
                        uVar19 = *(undefined4 *)(iVar21 + 4);
LAB_00426944:
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar13,"Name \'%s\' too long\n",uVar19);
                      }
                      goto LAB_00425224;
                    }
                  }
                  goto LAB_00425d70;
                }
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"No template, please set one up.\n");
              }
              else {
                iVar21 = build_subject(piVar38,pcStack_580,iStack_594);
                if (iVar21 != 0) {
LAB_00425d70:
                  iVar20 = (*(code *)PTR_X509_REQ_set_pubkey_006a8030)(piVar38,iVar20);
                  pcVar35 = pcVar39;
                  if (iVar20 != 0) {
                    if ((bVar4) &&
                       (iVar20 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*piVar38 + 0x18)),
                       iVar20 == 0)) {
                      (*(code *)PTR_sk_free_006a7f80)(*(undefined4 *)(*piVar38 + 0x18));
                      *(undefined4 *)(*piVar38 + 0x18) = 0;
                    }
                    if (bVar5) {
                      pcStack_580 = (char *)0x0;
                      goto LAB_004255dc;
                    }
                    (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_50c,0,0,piVar38,0,0);
                    (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_50c,req_conf);
                    if ((pcStack_588 == (char *)0x0) ||
                       (iVar20 = (*(code *)PTR_X509V3_EXT_REQ_add_nconf_006a8034)
                                           (req_conf,auStack_50c,pcStack_588,piVar38), iVar20 != 0))
                    {
                      iVar20 = do_X509_REQ_sign(*(undefined4 *)puVar13,piVar38,iStack_524,iStack_564
                                                ,puStack_5b8);
                      if (iVar20 != 0) goto LAB_00425698;
                      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar13,"Error Loading extension section %s\n",
                                 pcStack_588);
                    }
                    goto LAB_00425e70;
                  }
                }
              }
            }
          }
        }
        goto LAB_00425224;
      }
LAB_00425e70:
      iVar20 = 0;
      piVar32 = (int *)0x0;
      goto LAB_004245dc;
    }
    if (pcStack_560 == (char *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar17,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
    }
    else {
      iVar20 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar17,0x6c,3,pcStack_560);
      pcVar35 = pcStack_560;
      if (iVar20 < 1) {
LAB_00426268:
        iVar20 = 0;
        (*(code *)PTR_perror_006aab88)(pcVar35);
        piVar38 = (int *)0x0;
        piVar32 = (int *)0x0;
        goto LAB_004245dc;
      }
    }
    if (piVar38 == (int *)0x1) {
      piVar38 = (int *)(*(code *)PTR_d2i_X509_REQ_bio_006a8080)(iVar17,0);
    }
    else {
      if (piVar38 != (int *)0x3) {
        iVar20 = 0;
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"bad input format specified for X509 request\n");
        piVar32 = (int *)0x0;
        goto LAB_004245dc;
      }
      piVar38 = (int *)(*(code *)PTR_PEM_read_bio_X509_REQ_006a7fe4)(iVar17,0,0,0);
    }
    if (piVar38 == (int *)0x0) {
      iVar20 = 0;
      piVar32 = (int *)0x0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"unable to load X509 request\n");
      goto LAB_004245dc;
    }
    if (bVar5) {
      if (iStack_524 == 0) goto LAB_00425644;
LAB_004255dc:
      piVar32 = (int *)(*(code *)PTR_X509_new_006a7fe8)();
      if ((piVar32 != (int *)0x0) &&
         ((pcStack_58c == (char *)0x0 ||
          (iVar20 = (*(code *)PTR_X509_set_version_006a7fec)(piVar32,2), iVar20 != 0)))) {
        if (iStack_5b4 == 0) {
          uVar19 = (*(code *)PTR_X509_get_serialNumber_006a809c)(piVar32);
          iVar20 = (*(code *)PTR_rand_serial_006a80a0)(0,uVar19);
          if (iVar20 != 0) {
            iVar20 = *piVar38;
            goto LAB_0042717c;
          }
        }
        else {
          iVar20 = (*(code *)PTR_X509_set_serialNumber_006a8084)(piVar32,iStack_5b4);
          if (iVar20 != 0) {
            iVar20 = *piVar38;
LAB_0042717c:
            iVar20 = (*(code *)PTR_X509_set_issuer_name_006a8088)
                               (piVar32,*(undefined4 *)(iVar20 + 0x10));
            if ((((iVar20 != 0) &&
                 (iVar20 = (*(code *)PTR_X509_gmtime_adj_006a808c)
                                     (**(undefined4 **)(*piVar32 + 0x10),0), iVar20 != 0)) &&
                (iVar20 = (*(code *)PTR_X509_time_adj_ex_006a8090)
                                    (*(undefined4 *)(*(int *)(*piVar32 + 0x10) + 4),iStack_548,0,0),
                iVar20 != 0)) &&
               (((iVar20 = (*(code *)PTR_X509_set_subject_name_006a8094)
                                     (piVar32,*(undefined4 *)(*piVar38 + 0x10)), iVar20 != 0 &&
                 (iVar20 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38), iVar20 != 0)) &&
                (iVar21 = (*(code *)PTR_X509_set_pubkey_006a8098)(piVar32,iVar20), iVar21 != 0)))) {
              (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar20);
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_50c,piVar32,piVar32,0,0,0);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_50c,req_conf);
              if ((pcStack_58c == (char *)0x0) ||
                 (iVar20 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                     (req_conf,auStack_50c,pcStack_58c,piVar32), iVar20 != 0)) {
                puVar14 = PTR_bio_err_006a7f3c;
                iVar20 = do_X509_sign(*(undefined4 *)puVar13,piVar32,iStack_524,iStack_564,
                                      puStack_5b8);
                if (iVar20 != 0) {
                  if (pcStack_580 == (char *)0x0) goto LAB_004256f4;
                  iVar20 = 0;
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar14,"Cannot modifiy certificate subject\n");
                  goto LAB_004245dc;
                }
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar14);
              }
              else {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"Error Loading extension section %s\n",pcStack_58c
                          );
              }
            }
          }
        }
      }
LAB_00425614:
      iVar20 = 0;
      goto LAB_004245dc;
    }
    if (pcStack_580 != (char *)0x0) {
      if (pcStack_578 == (char *)0x0) {
        iVar20 = build_subject(piVar38,pcStack_580,iStack_594);
        if (iVar20 == 0) {
LAB_00426fcc:
          iVar20 = 0;
          piVar32 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"ERROR: cannot modify subject\n");
          goto LAB_004245dc;
        }
        *(undefined4 *)(*piVar38 + 8) = 1;
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"Modifying Request\'s Subject\n");
        (*(code *)PTR_print_name_006a8004)
                  (*(undefined4 *)puVar13,"old subject=",*(undefined4 *)(*piVar38 + 0x10),uStack_530
                  );
        iVar20 = build_subject(piVar38,pcStack_580,iStack_594,uStack_55c);
        puVar14 = PTR_print_name_006a8004;
        if (iVar20 == 0) goto LAB_00426fcc;
        iVar20 = *piVar38;
        uVar19 = *(undefined4 *)PTR_bio_err_006a7f3c;
        *(undefined4 *)(iVar20 + 8) = 1;
        (*(code *)puVar14)(uVar19,"new subject=",*(undefined4 *)(iVar20 + 0x10),uStack_530);
      }
    }
LAB_00425698:
    piVar32 = (int *)0x0;
    if (bVar6) {
      if (iStack_524 == 0) {
        iStack_524 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38);
        if (iStack_524 == 0) goto LAB_00425e70;
        iVar20 = (*(code *)PTR_X509_REQ_verify_006a7ff0)(piVar38,iStack_524);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iStack_524);
        iStack_524 = 0;
      }
      else {
        iVar20 = (*(code *)PTR_X509_REQ_verify_006a7ff0)(piVar38);
      }
      if (iVar20 < 0) goto LAB_00425e70;
      if (iVar20 == 0) {
        piVar32 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
      }
      else {
        piVar32 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"verify OK\n");
      }
    }
LAB_004256f4:
    if ((((!bVar7) || (bVar8)) || (bVar9)) || ((bVar10 || (bVar11)))) {
      if (pcStack_574 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
      }
      else {
        if ((pcStack_57c == (char *)0x0) ||
           (iVar20 = (*(code *)PTR_strcmp_006aac20)(pcStack_574,pcStack_57c), iVar20 != 0)) {
          uVar19 = 5;
        }
        else {
          uVar19 = 9;
        }
        iVar20 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6c,uVar19,pcStack_574);
        if (iVar20 == 0) {
          iVar20 = 0;
          (*(code *)PTR_perror_006aab88)(pcStack_574);
          goto LAB_004245dc;
        }
      }
      if (bVar11) {
        iVar20 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38);
        if (iVar20 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"Error getting public key\n");
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
          goto LAB_004245dc;
        }
        (*(code *)PTR_PEM_write_bio_PUBKEY_006a8028)(iVar18,iVar20);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar20);
      }
      if (bVar8) {
        if (bVar5) {
          (*(code *)PTR_X509_print_ex_006a7ffc)(iVar18,piVar32,uStack_530,uStack_52c);
          if (bVar10) goto LAB_004257c4;
          if (!bVar9) goto LAB_00425894;
LAB_004257fc:
          iVar20 = (*(code *)PTR_X509_get_pubkey_006a8008)(piVar32);
        }
        else {
          (*(code *)PTR_X509_REQ_print_ex_006a7ff8)(iVar18,piVar38,uStack_530,uStack_52c);
          if (bVar10) {
LAB_00425a44:
            (*(code *)PTR_print_name_006a8004)
                      (iVar18,"subject=",*(undefined4 *)(*piVar38 + 0x10),uStack_530);
          }
          if (!bVar9) goto LAB_00425894;
LAB_00425a74:
          iVar20 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38);
        }
        puVar14 = PTR_stdout_006aaad4;
        if (iVar20 == 0) {
          (*(code *)PTR_fwrite_006aab7c)
                    ("Modulus=unavailable\n",1,0x14,*(undefined4 *)PTR_stdout_006aaad4);
          goto LAB_004245dc;
        }
        (*(code *)PTR_fwrite_006aab7c)("Modulus=",1,8,*(undefined4 *)PTR_stdout_006aaad4);
        iVar21 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(iVar20);
        if (iVar21 == 6) {
          (*(code *)PTR_BN_print_006a8024)(iVar18,*(undefined4 *)(*(int *)(iVar20 + 0x14) + 0x10));
        }
        else {
          (*(code *)PTR_fwrite_006aab7c)("Wrong Algorithm type",1,0x14,*(undefined4 *)puVar14);
        }
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar20);
        (*(code *)PTR_fputc_006aaab0)(10,*(undefined4 *)puVar14);
      }
      else if (bVar10) {
        if (!bVar5) goto LAB_00425a44;
LAB_004257c4:
        uVar19 = (*(code *)PTR_X509_get_subject_name_006a8000)(piVar32);
        (*(code *)PTR_print_name_006a8004)(iVar18,"subject=",uVar19,uStack_530);
        if (bVar9) goto LAB_004257fc;
      }
      else if (bVar9) {
        if (bVar5) goto LAB_004257fc;
        goto LAB_00425a74;
      }
LAB_00425894:
      if (!bVar7) {
        if (bVar5) {
          if (piVar32 != (int *)0x0) {
            if (pcVar39 == (char *)0x1) {
              iVar20 = (*(code *)PTR_i2d_X509_bio_006a801c)(iVar18,piVar32);
            }
            else {
              if (pcVar39 != (char *)0x3) goto LAB_0042591c;
              iVar20 = (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar18,piVar32);
            }
            if (iVar20 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar13,"unable to write X509 certificate\n");
              goto LAB_00425614;
            }
          }
        }
        else {
          if (pcVar39 == (char *)0x1) {
            iVar20 = (*(code *)PTR_i2d_X509_REQ_bio_006a8010)(iVar18,piVar38);
          }
          else {
            if (pcVar39 != (char *)0x3) {
LAB_0042591c:
              iVar20 = 0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar13,"bad output format specified for outfile\n");
              goto LAB_004245dc;
            }
            if (bVar12) {
              iVar20 = (*(code *)PTR_PEM_write_bio_X509_REQ_NEW_006a8018)(iVar18,piVar38);
            }
            else {
              iVar20 = (*(code *)PTR_PEM_write_bio_X509_REQ_006a8014)(iVar18,piVar38);
            }
          }
          if (iVar20 == 0) goto LAB_004258ec;
        }
      }
    }
    iVar20 = 0;
    uVar36 = 0;
  } while( true );
LAB_00426a94:
  uStack_55c = 0x630000;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"weird input :-(\n");
LAB_00425224:
  if ((bVar4) &&
     (iVar20 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*piVar38 + 0x18)), iVar20 == 0)) {
    (*(code *)PTR_sk_free_006a7f80)(*(undefined4 *)(*piVar38 + 0x18));
    *(undefined4 *)(*piVar38 + 0x18) = 0;
  }
  iVar20 = 0;
  piVar32 = (int *)0x0;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"problems making Certificate Request\n")
  ;
  pcVar39 = pcVar35;
  goto LAB_004245dc;
LAB_00426bfc:
  iStack_5ac = iStack_5ac + 1;
  goto LAB_00426ba4;
LAB_004258ec:
  iVar20 = 0;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"unable to write X509 request\n");
  goto LAB_004245dc;
}

