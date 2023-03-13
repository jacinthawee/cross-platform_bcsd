
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
  int iVar29;
  undefined4 *puVar30;
  byte bVar31;
  char **ppcVar32;
  int *piVar33;
  byte *pbVar34;
  char **ppcVar35;
  char *pcVar36;
  uint uVar37;
  int *piVar38;
  char *pcVar39;
  code *pcVar40;
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
  char *pcStack_55c;
  char *pcStack_558;
  int iStack_548;
  int iStack_544;
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
  
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  puStack_7c = auStack_3c;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_7c);
  local_40 = 0;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_7c);
  puVar30 = &local_40;
  iVar17 = (*(code *)PTR_EVP_DigestSignInit_006a6e20)(puStack_7c,puVar30,param_4,0);
  if (iVar17 == 0) {
LAB_004242c8:
    uStack_88 = 0;
  }
  else {
    for (iVar17 = 0; iVar18 = (*(code *)PTR_sk_num_006a6e2c)(param_5), iVar17 < iVar18;
        iVar17 = iVar17 + 1) {
      param_3 = (*(code *)PTR_sk_value_006a6e24)(param_5,iVar17);
      iVar18 = (*(code *)PTR_pkey_ctrl_string_006a6e28)(local_40,param_3);
      if (iVar18 < 1) {
        puVar30 = (undefined4 *)0x633dc4;
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"parameter error \"%s\"\n",param_3);
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
        goto LAB_004242c8;
      }
    }
    puVar30 = puStack_7c;
    iVar17 = (*(code *)PTR_X509_REQ_sign_ctx_006a6e44)(param_2);
    uStack_88 = (uint)(0 < iVar17);
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(puStack_7c);
  if (local_24 == *(int *)puStack_78) {
    return uStack_88;
  }
  iVar17 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar15 = PTR___stack_chk_guard_006a9ae8;
  puVar13 = PTR_bio_err_006a6e3c;
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
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_80 = param_3;
  uStack_74 = param_2;
  uStack_70 = param_1;
  iStack_568 = (*(code *)PTR_EVP_des_ede3_cbc_006a6e48)();
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  if (*(int *)puVar13 == 0) {
    uVar19 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar18 = (*(code *)PTR_BIO_new_006a6ea4)(uVar19);
    *(int *)puVar13 = iVar18;
    if (iVar18 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
    }
  }
  uVar19 = *puVar30;
  iVar17 = iVar17 + -1;
  ppcVar32 = (char **)(puVar30 + 1);
  iStack_594 = 0x1001;
  if (iVar17 < 1) {
    pcStack_558 = (char *)0x0;
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
    pcStack_574 = (char *)0x0;
    pcStack_59c = (char *)0x0;
    pcStack_5a8 = (char *)0x0;
    pcStack_578 = (char *)0x0;
    pcStack_55c = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    pcStack_53c = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    pcStack_57c = (char *)0x0;
    pcStack_598 = (char *)0x0;
    puStack_5b8 = (undefined4 *)0x0;
    puStack_5c4 = (undefined4 *)0x0;
    pcStack_560 = (char *)0x0;
    iStack_544 = 0x1e;
    bVar5 = false;
    iStack_5d0 = 0;
    iStack_564 = 0;
    iStack_548 = 0;
  }
  else {
    iStack_564 = 0;
    iStack_548 = 0;
    pcStack_558 = (char *)0x0;
    uStack_540 = 3;
    pcStack_580 = (char *)0x0;
    pcVar39 = (char *)0x3;
    pcStack_5bc = (char *)0x0;
    piVar38 = (int *)0x3;
    iStack_544 = 0x1e;
    pcStack_5c0 = (char *)0x0;
    pcStack_534 = (char *)0x0;
    bVar9 = false;
    iStack_5b4 = 0;
    pcStack_588 = (char *)0x0;
    pcStack_58c = (char *)0x0;
    pcStack_5d8 = (char *)0x0;
    pcStack_574 = (char *)0x0;
    pcStack_59c = (char *)0x0;
    pcStack_5a8 = (char *)0x0;
    pcStack_578 = (char *)0x0;
    pcStack_55c = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    pcStack_53c = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    pcStack_57c = (char *)0x0;
    pcStack_598 = (char *)0x0;
    puStack_5b8 = (undefined4 *)0x0;
    puStack_5c4 = (undefined4 *)0x0;
    pcStack_560 = (char *)0x0;
    bVar5 = false;
    iStack_5d0 = 0;
LAB_004244a8:
    do {
      pcVar36 = *ppcVar32;
      iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-inform");
      iVar18 = iStack_564;
      if (iVar20 == 0) {
        iVar17 = iVar17 + -1;
        if (iVar17 != 0) {
          piVar38 = (int *)(*(code *)PTR_str2fmt_006a6e4c)(ppcVar32[1]);
          ppcVar35 = ppcVar32 + 1;
          goto LAB_0042449c;
        }
LAB_0042485c:
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"%s [options] <infile >outfile\n",uVar19);
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"where options  are\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -inform arg    input format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -outform arg   output format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13," -in arg        input file\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13," -out arg       output file\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -text          text form of request\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -pubkey        output public key\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -noout         do not output REQ\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -verify        verify signature on REQ\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13," -modulus       RSA modulus\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -nodes         don\'t encrypt the output key\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -engine e      use engine e, possibly a hardware device\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -subject       output the request\'s subject\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -passin        private key password source\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -key file      use the private key contained in file\n")
        ;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -keyform arg   key file format\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -keyout arg    file to send the key to\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -rand file%cfile%c...\n",0x3a,0x3a);
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   "                load the file (or the files in the directory) into\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"                the random number generator\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -newkey rsa:bits generate a new RSA key of \'bits\' in size\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -newkey dsa:file generate a new DSA key, parameters taken from CA in \'file\'\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -newkey ec:file generate a new EC key, parameters taken from CA in \'file\'\n")
        ;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -[digest]      Digest to sign with (md5, sha1, md2, mdc2, md4)\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -config file   request template file.\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -subj arg      set or modify request subject\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -multivalue-rdn enable support for multivalued RDNs\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13," -new           new request.\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -batch         do not ask anything during request generation\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -x509          output a x509 structure instead of a cert. req.\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -days          number of days a certificate generated by -x509 is valid for.\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -set_serial    serial number to use for a certificate generated by -x509.\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -newhdr        output \"NEW\" in the header lines\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -asn1-kludge   Output the \'request\' in a format that is wrong but some CA\'s\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"                have been reported as requiring\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -extensions .. specify certificate extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -reqexts ..    specify request extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -utf8          input characters are UTF8 (default ASCII)\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -nameopt arg    - various certificate name options\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -reqopt arg    - various request text options\n\n");
        goto LAB_00424800;
      }
      iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-outform");
      if (iVar20 != 0) {
        iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-engine");
        if (iVar20 == 0) {
          iVar17 = iVar17 + -1;
          if (iVar17 == 0) goto LAB_0042485c;
          pcStack_5d8 = ppcVar32[1];
          ppcVar35 = ppcVar32 + 1;
        }
        else {
          iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-keygen_engine");
          if (iVar20 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_0042485c;
            iStack_5d0 = (*(code *)PTR_ENGINE_by_id_006a6e9c)(ppcVar32[1]);
            ppcVar35 = ppcVar32 + 1;
            if (iStack_5d0 == 0) {
              pcVar36 = ppcVar32[1];
              uVar19 = *(undefined4 *)puVar13;
              pcVar28 = "Can\'t find keygen engine %s\n";
              goto LAB_004247f4;
            }
          }
          else {
            iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,&DAT_006326ec);
            if (iVar20 == 0) {
              iVar17 = iVar17 + -1;
              if (iVar17 == 0) goto LAB_0042485c;
              pcStack_5a8 = ppcVar32[1];
              ppcVar35 = ppcVar32 + 1;
            }
            else {
              iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-pubkey");
              ppcVar35 = ppcVar32;
              if (iVar20 == 0) {
                bVar11 = true;
              }
              else {
                iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,&DAT_006326fc);
                if (iVar20 == 0) {
                  pcStack_598 = (char *)0x1;
                }
                else {
                  iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-config");
                  if (iVar20 == 0) {
                    iVar17 = iVar17 + -1;
                    if (iVar17 == 0) goto LAB_0042485c;
                    pcStack_59c = ppcVar32[1];
                    ppcVar35 = ppcVar32 + 1;
                  }
                  else {
                    iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-keyform");
                    if (iVar20 == 0) {
                      iVar17 = iVar17 + -1;
                      if (iVar17 == 0) goto LAB_0042485c;
                      uStack_540 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar32[1]);
                      ppcVar35 = ppcVar32 + 1;
                    }
                    else if ((((*pcVar36 == '-') && (pcVar36[1] == 'i')) && (pcVar36[2] == 'n')) &&
                            (pcVar36[3] == '\0')) {
                      iVar17 = iVar17 + -1;
                      if (iVar17 == 0) goto LAB_0042485c;
                      pcStack_55c = ppcVar32[1];
                      ppcVar35 = ppcVar32 + 1;
                    }
                    else {
                      iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,&DAT_00632514);
                      if (iVar20 == 0) {
                        iVar17 = iVar17 + -1;
                        if (iVar17 == 0) goto LAB_0042485c;
                        pcStack_578 = ppcVar32[1];
                        ppcVar35 = ppcVar32 + 1;
                      }
                      else {
                        iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-keyout");
                        if (iVar20 == 0) {
                          iVar17 = iVar17 + -1;
                          if (iVar17 == 0) goto LAB_0042485c;
                          pcStack_574 = ppcVar32[1];
                          ppcVar35 = ppcVar32 + 1;
                        }
                        else {
                          iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-passin");
                          if (iVar20 == 0) {
                            iVar17 = iVar17 + -1;
                            if (iVar17 == 0) goto LAB_0042485c;
                            pcStack_5c0 = ppcVar32[1];
                            ppcVar35 = ppcVar32 + 1;
                          }
                          else {
                            iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-passout");
                            if (iVar20 == 0) {
                              iVar17 = iVar17 + -1;
                              if (iVar17 == 0) goto LAB_0042485c;
                              pcStack_5bc = ppcVar32[1];
                              ppcVar35 = ppcVar32 + 1;
                            }
                            else {
                              iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-rand");
                              if (iVar20 == 0) {
                                iVar17 = iVar17 + -1;
                                if (iVar17 == 0) goto LAB_0042485c;
                                pcStack_534 = ppcVar32[1];
                                ppcVar35 = ppcVar32 + 1;
                              }
                              else {
                                iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-newkey");
                                if (iVar20 != 0) {
                                  iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-pkeyopt");
                                  if (iVar20 == 0) {
                                    if (iVar17 != 1) {
                                      puVar30 = puStack_5c4;
                                      pcVar40 = (code *)PTR_sk_push_006a6fa8;
                                      if (puStack_5c4 == (undefined4 *)0x0) {
                                        puVar30 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a6fa4)();
                                        puStack_5c4 = puVar30;
                                        pcVar40 = (code *)PTR_sk_push_006a6fa8;
joined_r0x00427498:
                                        PTR_sk_push_006a6fa8 = pcVar40;
                                        if (puVar30 == (undefined4 *)0x0) goto LAB_0042485c;
                                      }
LAB_00427414:
                                      iVar20 = (*pcVar40)(puVar30,ppcVar32[1]);
joined_r0x004277e0:
                                      iVar17 = iVar17 + -1;
                                      ppcVar35 = ppcVar32 + 1;
                                      if (iVar20 != 0) goto LAB_0042449c;
                                    }
                                  }
                                  else {
                                    iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-sigopt");
                                    if (iVar20 != 0) {
                                      iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-batch");
                                      if (iVar20 == 0) {
                                        batch = 1;
                                      }
                                      else {
                                        iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-newhdr");
                                        if (iVar20 == 0) {
                                          bVar12 = true;
                                        }
                                        else {
                                          iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                             (pcVar36,"-modulus");
                                          if (iVar20 == 0) {
                                            bVar9 = true;
                                          }
                                          else {
                                            iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                               (pcVar36,"-verify");
                                            if (iVar20 == 0) {
                                              bVar6 = true;
                                            }
                                            else {
                                              iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (pcVar36,"-nodes");
                                              if (iVar20 == 0) {
                                                pcStack_53c = (char *)0x1;
                                              }
                                              else {
                                                iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                   (pcVar36,"-noout");
                                                if (iVar20 == 0) {
                                                  bVar7 = true;
                                                }
                                                else {
                                                  iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (pcVar36,"-verbose");
                                                  if (iVar20 == 0) {
                                                    pcStack_57c = (char *)0x1;
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar36,"-utf8");
                                                    if (iVar20 != 0) {
                                                      iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar36,"-nameopt");
                                                      if (iVar20 == 0) {
                                                        if (iVar17 != 1) {
                                                          puVar30 = &uStack_530;
                                                          pcVar40 = (code *)PTR_set_name_ex_006a6fac
                                                          ;
                                                          goto LAB_00427414;
                                                        }
                                                      }
                                                      else {
                                                        iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar36,"-reqopt");
                                                        if (iVar20 != 0) {
                                                          iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (pcVar36,"-subject");
                                                          if (iVar20 == 0) {
                                                            bVar10 = true;
                                                          }
                                                          else {
                                                            iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (pcVar36,"-text");
                                                            if (iVar20 == 0) {
                                                              bVar8 = true;
                                                            }
                                                            else {
                                                              iVar20 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(pcVar36,"-x509");
                                                              if (iVar20 == 0) {
                                                                bVar5 = true;
                                                              }
                                                              else {
                                                                iVar20 = (*(code *)
                                                  PTR_strcmp_006a9b18)(pcVar36,"-asn1-kludge");
                                                  if (iVar20 == 0) {
                                                    bVar4 = true;
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar36,"-no-asn1-kludge");
                                                    if (iVar20 == 0) {
                                                      bVar4 = false;
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar36,"-subj");
                                                      if (iVar20 == 0) {
                                                        iVar17 = iVar17 + -1;
                                                        if (iVar17 == 0) goto LAB_0042485c;
                                                        pcStack_580 = ppcVar32[1];
                                                        ppcVar35 = ppcVar32 + 1;
                                                      }
                                                      else {
                                                        iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar36,
                                                  "-multivalue-rdn");
                                                  if (iVar20 == 0) {
                                                    pcStack_558 = (char *)0x1;
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar36,"-days");
                                                    if (iVar20 == 0) {
                                                      iVar17 = iVar17 + -1;
                                                      if (iVar17 == 0) goto LAB_0042485c;
                                                      ppcVar35 = ppcVar32 + 1;
                                                      iVar20 = (*(code *)PTR_strtol_006a9958)
                                                                         (ppcVar32[1],0,10);
                                                      iStack_544 = 0x1e;
                                                      if (iVar20 != 0) {
                                                        iStack_544 = iVar20;
                                                      }
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar36,"-set_serial");
                                                      if (iVar20 == 0) {
                                                        if (iVar17 == 1) goto LAB_0042485c;
                                                        iStack_5b4 = (*(code *)
                                                  PTR_s2i_ASN1_INTEGER_006a6fb4)(0,ppcVar32[1]);
                                                  iVar20 = iStack_5b4;
                                                  goto joined_r0x004277e0;
                                                  }
                                                  iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (pcVar36,"-extensions");
                                                  if (iVar20 == 0) {
                                                    iVar17 = iVar17 + -1;
                                                    if (iVar17 == 0) goto LAB_0042485c;
                                                    pcStack_58c = ppcVar32[1];
                                                    ppcVar35 = ppcVar32 + 1;
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar36,"-reqexts");
                                                    if (iVar20 == 0) {
                                                      iVar17 = iVar17 + -1;
                                                      if (iVar17 == 0) goto LAB_0042485c;
                                                      pcStack_588 = ppcVar32[1];
                                                      ppcVar35 = ppcVar32 + 1;
                                                    }
                                                    else {
                                                      iStack_548 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a6f2c)(pcVar36 + 1);
                                                  iVar18 = iStack_548;
                                                  if (iStack_548 == 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar13,
                                                               "unknown option %s\n",*ppcVar32);
                                                    goto LAB_0042485c;
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
                                                  goto LAB_0042449c;
                                                  }
                                                  if (iVar17 != 1) {
                                                    puVar30 = &uStack_52c;
                                                    pcVar40 = (code *)PTR_set_cert_ex_006a6fb0;
                                                    goto LAB_00427414;
                                                  }
                                                  }
                                                  goto LAB_0042485c;
                                                  }
                                                  iStack_594 = 0x1000;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      goto LAB_0042449c;
                                    }
                                    if (iVar17 != 1) {
                                      puVar30 = puStack_5b8;
                                      pcVar40 = (code *)PTR_sk_push_006a6fa8;
                                      if (puStack_5b8 == (undefined4 *)0x0) {
                                        puVar30 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a6fa4)();
                                        puStack_5b8 = puVar30;
                                        pcVar40 = (code *)PTR_sk_push_006a6fa8;
                                        goto joined_r0x00427498;
                                      }
                                      goto LAB_00427414;
                                    }
                                  }
                                  goto LAB_0042485c;
                                }
                                iVar17 = iVar17 + -1;
                                if (iVar17 == 0) goto LAB_0042485c;
                                pcStack_560 = ppcVar32[1];
                                pcStack_598 = (char *)0x1;
                                ppcVar35 = ppcVar32 + 1;
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
LAB_0042449c:
        iStack_564 = iVar18;
        iVar17 = iVar17 + -1;
        ppcVar32 = ppcVar35 + 1;
        if (iVar17 == 0) break;
        goto LAB_004244a8;
      }
      if (iVar17 == 1) goto LAB_0042485c;
      ppcVar35 = ppcVar32 + 1;
      iVar17 = iVar17 + -2;
      ppcVar32 = ppcVar32 + 2;
      pcVar39 = (char *)(*(code *)PTR_str2fmt_006a6e4c)(*ppcVar35);
    } while (iVar17 != 0);
  }
  puVar14 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  iVar17 = (*(code *)PTR_app_passwd_006a6e54)
                     (*(undefined4 *)puVar13,pcStack_5c0,pcStack_5bc,&iStack_518,&iStack_514);
  if (iVar17 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar14,"Error getting passwords\n");
  }
  else {
    if (pcStack_59c == (char *)0x0) {
      req_conf = *(int *)PTR_config_006a6e68;
      if (req_conf == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar14,"Unable to load config info from %s\n",
                   *(undefined4 *)PTR_default_config_file_006a6edc);
        if (pcStack_598 != (char *)0x0) {
          iVar18 = 0;
          iVar17 = 0;
          goto LAB_004245c0;
        }
LAB_00424594:
        if (req_conf != 0) goto LAB_004245a8;
LAB_00424e14:
        iVar17 = (*(code *)PTR_add_oid_section_006a6e60)(*(undefined4 *)puVar13,req_conf);
        if (iVar17 != 0) {
          if (iStack_548 == 0) {
            iVar17 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,&DAT_00631a94,"default_md");
            if (iVar17 == 0) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            else {
              iVar17 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(iVar17);
              if (iVar17 != 0) {
                iStack_564 = iVar17;
              }
            }
          }
          if ((pcStack_58c == (char *)0x0) &&
             (pcStack_58c = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                              (req_conf,&DAT_00631a94,"x509_extensions"),
             pcStack_58c == (char *)0x0)) {
            (*(code *)PTR_ERR_clear_error_006a6ee0)();
LAB_00424ea4:
            piVar33 = (int *)0x630000;
            if ((iStack_518 == 0) &&
               (iStack_518 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                                       (req_conf,&DAT_00631a94,"input_password"), iStack_518 == 0))
            {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            if ((iStack_514 == 0) &&
               (iStack_514 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                                       (req_conf,&DAT_00631a94,"output_password"), iStack_514 == 0))
            {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                        (req_conf,&DAT_00631a94,"string_mask");
            if (pcVar36 == (char *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            else {
              iVar17 = (*(code *)PTR_ASN1_STRING_set_default_mask_asc_006a6ec0)(pcVar36);
              if (iVar17 == 0) {
                uVar19 = *(undefined4 *)puVar13;
                pcVar28 = "Invalid global string mask setting %s\n";
                goto LAB_004247f4;
              }
            }
            if (iStack_594 == 0x1000) {
LAB_00424f5c:
              iStack_594 = 0x1000;
            }
            else {
              pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                          (req_conf,&DAT_00631a94,&DAT_00633198);
              if (pcVar36 == (char *)0x0) {
                (*(code *)PTR_ERR_clear_error_006a6ee0)();
              }
              else if ((((*pcVar36 == 'y') && (pcVar36[1] == 'e')) && (pcVar36[2] == 's')) &&
                      (pcVar36[3] == '\0')) goto LAB_00424f5c;
            }
            if ((pcStack_588 == (char *)0x0) &&
               (pcStack_588 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                (req_conf,&DAT_00631a94,"req_extensions"),
               pcStack_588 == (char *)0x0)) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            else {
              (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_50c,0,0,0,0,1);
              (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_50c,req_conf);
              iVar17 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                 (req_conf,auStack_50c,pcStack_588,0);
              if (iVar17 == 0) {
                uVar19 = *(undefined4 *)puVar13;
                pcVar28 = "Error Loading request extension section %s\n";
                pcVar36 = pcStack_588;
                goto LAB_004247f4;
              }
            }
            uVar19 = (*(code *)PTR_BIO_s_file_006a6ea0)();
            iVar17 = (*(code *)PTR_BIO_new_006a6ea4)(uVar19);
            uVar19 = (*(code *)PTR_BIO_s_file_006a6ea0)();
            iVar18 = (*(code *)PTR_BIO_new_006a6ea4)(uVar19);
            if ((iVar17 != 0) && (iVar18 != 0)) {
              uVar19 = (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar13,pcStack_5d8,0);
              if (pcStack_5a8 == (char *)0x0) goto LAB_004250bc;
              iStack_524 = (*(code *)PTR_load_key_006a6ec8)
                                     (*(undefined4 *)PTR_bio_err_006a6e3c,pcStack_5a8,uStack_540,0,
                                      iStack_518,uVar19,"Private Key");
              if (iStack_524 != 0) {
                iVar20 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,&DAT_00631a94,"RANDFILE")
                ;
                if (iVar20 == 0) goto LAB_00425c40;
                goto LAB_004250a4;
              }
            }
            goto LAB_004245c0;
          }
          (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_50c,0,0,0,0,1);
          (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_50c,req_conf);
          iVar17 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)(req_conf,auStack_50c,pcStack_58c,0);
          if (iVar17 != 0) goto LAB_00424ea4;
          uVar19 = *(undefined4 *)puVar13;
          pcVar28 = "Error Loading extension section %s\n";
          pcVar36 = pcStack_58c;
LAB_004247f4:
          (*(code *)PTR_BIO_printf_006a6e38)(uVar19,pcVar28,pcVar36);
          goto LAB_00424800;
        }
      }
      else {
        if (pcStack_57c != (char *)0x0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar14,"Using configuration from %s\n",
                     *(undefined4 *)PTR_default_config_file_006a6edc);
          goto LAB_00424594;
        }
LAB_004245a8:
        iVar17 = (*(code *)PTR_load_config_006a6e64)(*(undefined4 *)puVar13);
        if (iVar17 != 0) {
          iVar17 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,0,"oid_file");
          if (iVar17 == 0) {
            (*(code *)PTR_ERR_clear_error_006a6ee0)();
          }
          else {
            iVar17 = (*(code *)PTR_BIO_new_file_006a6eac)(iVar17,"r");
            if (iVar17 != 0) {
              (*(code *)PTR_OBJ_create_objects_006a6eb0)(iVar17);
              (*(code *)PTR_BIO_free_006a6e70)(iVar17);
            }
          }
          goto LAB_00424e14;
        }
      }
      iVar18 = 0;
      iVar17 = 0;
      goto LAB_004245c0;
    }
    auStack_50c[0] = 0xffffffff;
    if (pcStack_57c != (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar14,"Using configuration from %s\n",pcStack_59c);
    }
    req_conf = (*(code *)PTR_NCONF_new_006a6e58)(0);
    iVar17 = (*(code *)PTR_NCONF_load_006a6e5c)(req_conf,pcStack_59c,auStack_50c);
    if (iVar17 != 0) goto LAB_00424594;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar13,"error on line %ld of %s\n",auStack_50c[0],pcStack_59c);
  }
LAB_00424800:
  iVar18 = 0;
  iVar17 = 0;
LAB_004245c0:
  iVar20 = 0;
LAB_004245c8:
  piVar38 = (int *)0x0;
  piVar33 = (int *)0x0;
LAB_004245cc:
  uVar37 = 1;
  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
  do {
    if ((req_conf != 0) && (req_conf != *(int *)PTR_config_006a6e68)) {
      (*(code *)PTR_NCONF_free_006a6e6c)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar17);
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar18);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(iStack_524);
    if (iVar20 != 0) {
      (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar20);
    }
    if (puStack_5c4 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a6e80)(puStack_5c4);
    }
    if (puStack_5b8 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a6e80)(puStack_5b8);
    }
    if (iStack_5d0 != 0) {
      (*(code *)PTR_ENGINE_free_006a6e84)(iStack_5d0);
    }
    if (iStack_528 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_X509_REQ_free_006a6e8c)(piVar38);
    (*(code *)PTR_X509_free_006a6e90)(piVar33);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iStack_5b4);
    if ((pcStack_5c0 != (char *)0x0) && (iStack_518 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if ((pcStack_5bc != (char *)0x0) && (iStack_514 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_OBJ_cleanup_006a6e98)();
    if (iStack_8c == *(int *)puVar15) {
      return uVar37;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00425c40:
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
LAB_004250a4:
    (*(code *)PTR_app_RAND_load_file_006a6ecc)(iVar20,*(undefined4 *)puVar13,0);
LAB_004250bc:
    if (pcStack_598 != (char *)0x0) {
      if (iStack_524 == 0) {
        iVar21 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,piVar33 + 0x6a5,"RANDFILE");
        if (iVar21 == 0) {
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
        (*(code *)PTR_app_RAND_load_file_006a6ecc)(iVar21,*(undefined4 *)puVar13,0);
        if (pcStack_534 != (char *)0x0) {
          (*(code *)PTR_app_RAND_load_files_006a6f38)(pcStack_534);
        }
        iVar20 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                           (req_conf,piVar33 + 0x6a5,"default_bits",&iStack_51c);
        if (iVar20 == 0) {
          iStack_51c = 0x200;
          if (pcStack_560 == (char *)0x0) {
LAB_00425fcc:
            iVar20 = set_keygen_ctx(*(undefined4 *)puVar13,0,&iStack_520,&iStack_51c,&iStack_528,
                                    iStack_5d0);
            if (iVar20 == 0) goto LAB_004245c8;
          }
          else {
LAB_00425f0c:
            iVar20 = set_keygen_ctx(*(undefined4 *)puVar13,pcStack_560,&iStack_520,&iStack_51c,
                                    &iStack_528,iStack_5d0);
            if (iVar20 == 0) goto LAB_004245c8;
            if (iStack_51c < 0x180) goto LAB_00425f48;
          }
        }
        else {
          if (pcStack_560 != (char *)0x0) goto LAB_00425f0c;
          if (0x17f < iStack_51c) goto LAB_00425fcc;
          iVar20 = 0;
LAB_00425f48:
          if ((iStack_520 == 6) || (iStack_520 == 0x74)) {
            piVar38 = (int *)0x0;
            piVar33 = (int *)0x0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar13,"private key length is too short,\n");
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar13,"it needs to be at least %d bits, not %ld\n",0x180,
                       iStack_51c);
            goto LAB_004245cc;
          }
          if (iVar20 == 0) goto LAB_00425fcc;
        }
        iVar22 = 0;
        if (puStack_5c4 != (undefined4 *)0x0) {
          for (; iVar23 = (*(code *)PTR_sk_num_006a6e2c)(puStack_5c4), iVar22 < iVar23;
              iVar22 = iVar22 + 1) {
            uVar19 = (*(code *)PTR_sk_value_006a6e24)(puStack_5c4,iVar22);
            iVar23 = (*(code *)PTR_pkey_ctrl_string_006a6e28)(iVar20,uVar19);
            if (iVar23 < 1) {
              piVar38 = (int *)0x0;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar13,"parameter error \"%s\"\n",uVar19);
              piVar33 = (int *)0x0;
              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
              goto LAB_004245cc;
            }
          }
        }
        puVar14 = PTR_bio_err_006a6e3c;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"Generating a %ld bit %s private key\n",iStack_51c,
                   iStack_528);
        (*(code *)PTR_EVP_PKEY_CTX_set_cb_006a6f40)(iVar20,genpkey_cb);
        (*(code *)PTR_EVP_PKEY_CTX_set_app_data_006a6f44)(iVar20,*(undefined4 *)puVar13);
        iVar22 = (*(code *)PTR_EVP_PKEY_keygen_006a6f48)(iVar20,&iStack_524);
        if (iVar22 < 1) {
          piVar33 = (int *)0x0;
          piVar38 = (int *)0x0;
          (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar14,"Error Generating Key\n");
          goto LAB_004245cc;
        }
        (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar20);
        (*(code *)PTR_app_RAND_write_file_006a6f4c)(iVar21,*(undefined4 *)puVar14);
        if ((pcStack_574 == (char *)0x0) &&
           (pcStack_574 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                            (req_conf,piVar33 + 0x6a5,"default_keyfile"),
           pcStack_574 == (char *)0x0)) {
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar14,"writing new private key to stdout\n");
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
        }
        else {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"writing new private key to \'%s\'\n",pcStack_574);
          iVar20 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6c,5,pcStack_574);
          pcVar36 = pcStack_574;
          if (iVar20 < 1) goto LAB_0042633c;
        }
        pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                    (req_conf,piVar33 + 0x6a5,"encrypt_rsa_key");
        if (pcVar36 == (char *)0x0) {
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
          pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                      (req_conf,piVar33 + 0x6a5,"encrypt_key");
          if (pcVar36 != (char *)0x0) goto LAB_004261ac;
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
        else {
LAB_004261ac:
          if (((*pcVar36 == 'n') && (pcVar36[1] == 'o')) && (pcVar36[2] == '\0')) {
            iStack_568 = 0;
          }
        }
        iVar20 = 4;
        if (pcStack_53c != (char *)0x0) {
          iStack_568 = 0;
        }
        while (iVar21 = (*(code *)PTR_PEM_write_bio_PrivateKey_006a6f50)
                                  (iVar18,iStack_524,iStack_568,0,0,0,iStack_514), iVar21 == 0) {
          uVar37 = (*(code *)PTR_ERR_peek_error_006a6f54)();
          if (((uVar37 & 0xfff) != 0x6d) || (iVar20 = iVar20 + -1, iVar20 == 0)) goto LAB_004245c0;
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"-----\n");
        if (iStack_524 == 0) {
LAB_00425634:
          iVar20 = 0;
          piVar33 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"you need to specify a private key\n");
          goto LAB_004245cc;
        }
      }
      piVar38 = (int *)(*(code *)PTR_X509_REQ_new_006a6ed0)();
      iVar20 = iStack_524;
      if (piVar38 != (int *)0x0) {
        iStack_568 = iStack_524;
        pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                    (req_conf,piVar33 + 0x6a5,"prompt");
        if (pcVar36 == (char *)0x0) {
          bVar2 = false;
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
        else {
          bVar2 = *pcVar36 == 'n';
          if ((*pcVar36 == 'n') && (bVar2 = pcVar36[1] == 'o', pcVar36[1] == 'o')) {
            bVar2 = pcVar36[2] == '\0';
          }
        }
        iVar21 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                           (req_conf,piVar33 + 0x6a5,"distinguished_name");
        pcVar36 = pcVar39;
        if (iVar21 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"unable to find \'%s\' in config\n","distinguished_name"
                    );
        }
        else {
          iVar22 = (*(code *)PTR_NCONF_get_section_006a6ed4)(req_conf,iVar21);
          if (iVar22 == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar21);
          }
          else {
            iVar23 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,piVar33 + 0x6a5,"attributes")
            ;
            if (iVar23 == 0) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
              pcStack_59c = (char *)0x0;
            }
            else {
              pcStack_59c = (char *)(*(code *)PTR_NCONF_get_section_006a6ed4)(req_conf,iVar23);
              if (pcStack_59c == (char *)0x0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar23);
                goto LAB_00425214;
              }
            }
            iVar24 = (*(code *)PTR_X509_REQ_set_version_006a6ed8)(piVar38,0);
            if (iVar24 != 0) {
              if (bVar2) {
                uVar19 = *(undefined4 *)(*piVar38 + 0x10);
                for (iVar21 = 0; iVar23 = (*(code *)PTR_sk_num_006a6e2c)(iVar22), iVar21 < iVar23;
                    iVar21 = iVar21 + 1) {
                  iVar23 = (*(code *)PTR_sk_value_006a6e24)(iVar22,iVar21);
                  pbVar26 = *(byte **)(iVar23 + 4);
                  bVar31 = *pbVar26;
                  pbVar34 = pbVar26;
                  while (bVar31 != 0) {
                    if ((bVar31 == 0x3a) || ((bVar31 & 0xfd) == 0x2c)) {
                      bVar31 = pbVar34[1];
                      if (bVar31 != 0) {
                        pbVar26 = pbVar34 + 1;
                      }
                      break;
                    }
                    pbVar34 = pbVar34 + 1;
                    bVar31 = *pbVar34;
                  }
                  iVar23 = (*(code *)PTR_X509_NAME_add_entry_by_txt_006a6f6c)
                                     (uVar19,pbVar26,iStack_594,*(undefined4 *)(iVar23 + 8),
                                      0xffffffff,0xffffffff,-(uint)(bVar31 == 0x2b));
                  if (iVar23 == 0) goto LAB_00425214;
                }
                iVar21 = (*(code *)PTR_X509_NAME_entry_count_006a6f70)(uVar19);
                if (iVar21 != 0) {
                  if (!bVar5) {
                    for (iVar21 = 0; iVar22 = (*(code *)PTR_sk_num_006a6e2c)(pcStack_59c),
                        iVar21 < iVar22; iVar21 = iVar21 + 1) {
                      iVar22 = (*(code *)PTR_sk_value_006a6e24)(pcStack_59c,iVar21);
                      iVar22 = (*(code *)PTR_X509_REQ_add1_attr_by_txt_006a6f74)
                                         (piVar38,*(undefined4 *)(iVar22 + 4),iStack_594,
                                          *(undefined4 *)(iVar22 + 8),0xffffffff);
                      if (iVar22 == 0) goto LAB_00425214;
                    }
                  }
                  goto LAB_00425d60;
                }
LAB_00426a90:
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar13,"error, no objects specified in config file\n");
                pcVar36 = pcVar39;
              }
              else if (pcStack_580 == (char *)0x0) {
                pcStack_598 = *(char **)(*piVar38 + 0x10);
                if (batch == 0) {
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "You are about to be asked to enter information that will be incorporated\n"
                            );
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,"into your certificate request.\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "What you are about to enter is what is called a Distinguished Name or a DN.\n"
                            );
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "There are quite a few fields but you can leave some blank\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "For some fields there will be a default value,\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "If you enter \'.\', the field will be left blank.\n");
                  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"-----\n");
                }
                iVar24 = (*(code *)PTR_sk_num_006a6e2c)(iVar22);
                if (iVar24 != 0) {
                  pcStack_580 = (char *)0xffffffff;
                  pcStack_558 = "";
                  pcStack_53c = "%s [%s]:";
                  pcStack_57c = "\n";
LAB_00426478:
                  pcStack_580 = pcStack_580 + 1;
                  iVar24 = (*(code *)PTR_sk_num_006a6e2c)(iVar22);
                  pcStack_534 = pcVar39;
                  if ((int)pcStack_580 < iVar24) {
                    iVar24 = (*(code *)PTR_sk_value_006a6e24)(iVar22,pcStack_580);
                    pbVar34 = *(byte **)(iVar24 + 4);
                    iVar25 = check_end(pbVar34,&DAT_0063354c);
                    if ((((iVar25 != 0) && (iVar25 = check_end(pbVar34,&DAT_00633554), iVar25 != 0))
                        && (iVar25 = check_end(pbVar34,"_default"), iVar25 != 0)) &&
                       (iVar25 = check_end(pbVar34,"_value"), iVar25 != 0)) {
                      bVar31 = *pbVar34;
                      if (bVar31 == 0) {
LAB_00426588:
                        pcVar36 = (char *)0x0;
                      }
                      else if ((bVar31 == 0x3a) || (pbVar26 = pbVar34, (bVar31 & 0xfd) == 0x2c)) {
                        pbVar26 = pbVar34;
                        bVar1 = pbVar34[1];
                        if (pbVar34[1] != 0) goto LAB_00426574;
                        pcVar36 = (char *)0x0;
                      }
                      else {
                        do {
                          pbVar3 = pbVar26;
                          pbVar26 = pbVar3 + 1;
                          bVar1 = *pbVar26;
                          if (bVar1 == 0) goto LAB_0042657c;
                        } while ((bVar1 != 0x3a) && ((bVar1 & 0xfd) != 0x2c));
                        bVar1 = pbVar3[2];
                        if (bVar1 != 0) {
LAB_00426574:
                          bVar31 = bVar1;
                          pbVar34 = pbVar26 + 1;
                        }
LAB_0042657c:
                        if (bVar31 != 0x2b) goto LAB_00426588;
                        pbVar34 = pbVar34 + 1;
                        pcVar36 = (char *)0xffffffff;
                      }
                      iVar25 = (*(code *)PTR_OBJ_txt2nid_006a6f5c)(pbVar34);
                      if (iVar25 != 0) {
                        iVar27 = (*(code *)PTR_BIO_snprintf_006a6f60)
                                           (auStack_4f0,100,"%s_default",*(undefined4 *)(iVar24 + 4)
                                           );
                        if (iVar27 < 100) {
                          pcVar28 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                      (req_conf,iVar21,auStack_4f0);
                          if (pcVar28 == (char *)0x0) {
                            pcVar28 = "";
                            (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          }
                          (*(code *)PTR_BIO_snprintf_006a6f60)
                                    (auStack_4f0,100,"%s_value",*(undefined4 *)(iVar24 + 4));
                          iVar27 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                                             (req_conf,iVar21,auStack_4f0);
                          if (iVar27 == 0) {
                            (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          }
                          (*(code *)PTR_BIO_snprintf_006a6f60)
                                    (auStack_4f0,100,"%s_min",*(undefined4 *)(iVar24 + 4));
                          iVar29 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                             (req_conf,iVar21,auStack_4f0,&pcStack_510);
                          if (iVar29 == 0) {
                            (*(code *)PTR_ERR_clear_error_006a6ee0)();
                            pcStack_510 = (char *)0xffffffff;
                          }
                          (*(code *)PTR_BIO_snprintf_006a6f60)
                                    (auStack_4f0,100,"%s_max",*(undefined4 *)(iVar24 + 4));
                          iVar29 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                             (req_conf,iVar21,auStack_4f0,auStack_50c);
                          if (iVar29 == 0) {
                            (*(code *)PTR_ERR_clear_error_006a6ee0)();
                            auStack_50c[0] = 0xffffffff;
                          }
                          uVar19 = auStack_50c[0];
                          pcVar16 = pcStack_510;
                          pcStack_55c = "";
                          pcStack_560 = *(char **)(iVar24 + 8);
                          if (batch == 0) goto LAB_00426808;
                          do {
                            (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar13,0xb,0,0);
                            if (iVar27 == 0) {
                              acStack_48d[1] = '\0';
                              if (batch == 0) {
                                iVar24 = (*(code *)PTR_fgets_006a9ae0)
                                                   (acStack_48d + 1,0x400,
                                                    *(undefined4 *)PTR_stdin_006a9a14);
                                if (iVar24 != 0) goto LAB_00426794;
                                goto LAB_00426a74;
                              }
                              acStack_48d[2] = '\0';
                              acStack_48d[1] = '\n';
LAB_00426a00:
                              if (*pcVar28 == '\0') goto LAB_00426478;
                              (*(code *)PTR_BUF_strlcpy_006a6f64)(acStack_48d + 1,pcVar28,0x400);
                              (*(code *)PTR_BUF_strlcat_006a6f68)(acStack_48d + 1,"\n",0x400);
                            }
                            else {
                              (*(code *)PTR_BUF_strlcpy_006a6f64)(acStack_48d + 1,iVar27,0x400);
                              (*(code *)PTR_BUF_strlcat_006a6f68)(acStack_48d + 1,"\n",0x400);
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)PTR_bio_err_006a6e3c,"%s\n",iVar27);
LAB_00426794:
                              if (acStack_48d[1] == '\0') goto LAB_00426a74;
                              if (acStack_48d[1] == '\n') goto LAB_00426a00;
                              if ((acStack_48d[1] == '.') && (acStack_48d[2] == '\n'))
                              goto LAB_00426478;
                            }
                            iVar24 = (*(code *)PTR_strlen_006a9a24)(acStack_48d + 1);
                            if (acStack_48d[iVar24] != '\n') goto LAB_00426aac;
                            acStack_48d[iVar24] = '\0';
                            iVar24 = req_check_len(iVar24 + -1,pcVar16,uVar19);
                            if (iVar24 != 0) goto LAB_00426a40;
                            if ((batch != 0) || (iVar27 != 0)) goto LAB_00426a74;
LAB_00426808:
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (*(undefined4 *)puVar13,"%s [%s]:",pcStack_560,pcVar28);
                          } while( true );
                        }
                        uVar19 = *(undefined4 *)(iVar24 + 4);
                        goto LAB_00426928;
                      }
                    }
                    goto LAB_00426478;
                  }
                  iVar21 = (*(code *)PTR_X509_NAME_entry_count_006a6f70)(pcStack_598);
                  if (iVar21 == 0) goto LAB_00426a90;
                  if ((!bVar5) && (pcStack_59c != (char *)0x0)) {
                    iVar21 = (*(code *)PTR_sk_num_006a6e2c)(pcStack_59c);
                    if ((0 < iVar21) && (batch == 0)) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar13,
                                 "\nPlease enter the following \'extra\' attributes\n");
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar13,"to be sent with your certificate request\n"
                                );
                    }
                    iStack_5ac = 0;
                    pcStack_560 = "";
                    pcStack_558 = "%s [%s]:";
                    pcStack_598 = "\n";
LAB_00426bc4:
                    pcStack_55c = "";
                    iVar21 = (*(code *)PTR_sk_num_006a6e2c)(pcStack_59c);
                    if (iStack_5ac < iVar21) {
                      iVar21 = (*(code *)PTR_sk_value_006a6e24)(pcStack_59c,iStack_5ac);
                      uVar19 = *(undefined4 *)(iVar21 + 4);
                      pcVar36 = (char *)(*(code *)PTR_OBJ_txt2nid_006a6f5c)(uVar19);
                      if (pcVar36 == (char *)0x0) goto LAB_00426c1c;
                      iVar22 = (*(code *)PTR_BIO_snprintf_006a6f60)
                                         (auStack_4f0,100,"%s_default",uVar19);
                      if (iVar22 < 100) {
                        pcVar28 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                    (req_conf,iVar23,auStack_4f0);
                        if (pcVar28 == (char *)0x0) {
                          pcVar28 = "";
                          (*(code *)PTR_ERR_clear_error_006a6ee0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_4f0,100,"%s_value",uVar19);
                        iVar22 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                                           (req_conf,iVar23,auStack_4f0);
                        if (iVar22 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a6ee0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_4f0,100,"%s_min",uVar19);
                        iVar24 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                           (req_conf,iVar23,auStack_4f0,&pcStack_510);
                        if (iVar24 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          pcStack_510 = (char *)0xffffffff;
                        }
                        (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_4f0,100,"%s_max",uVar19);
                        iVar24 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                           (req_conf,iVar23,auStack_4f0,auStack_50c);
                        if (iVar24 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          auStack_50c[0] = 0xffffffff;
                        }
                        uVar19 = auStack_50c[0];
                        pcVar16 = pcStack_510;
                        puVar14 = PTR_bio_err_006a6e3c;
                        pcStack_580 = *(char **)(iVar21 + 8);
                        pcStack_57c = pcStack_510;
                        if (batch == 0) goto LAB_00426ea4;
                        do {
                          (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar13,0xb,0,0);
                          if (iVar22 == 0) {
                            buf_16723[0] = '\0';
                            if (batch == 0) {
                              iVar21 = (*(code *)PTR_fgets_006a9ae0)
                                                 (buf_16723,0x400,*(undefined4 *)PTR_stdin_006a9a14)
                              ;
                              if (iVar21 != 0) goto LAB_00426e34;
                              goto LAB_00426a74;
                            }
                            buf_16723[0] = '\n';
                            buf_16723[1] = '\0';
LAB_00426f74:
                            if (*pcVar28 == '\0') goto LAB_00426c1c;
                            (*(code *)PTR_BUF_strlcpy_006a6f64)(buf_16723,pcVar28,0x400);
                            (*(code *)PTR_BUF_strlcat_006a6f68)(buf_16723,"\n",0x400);
                          }
                          else {
                            (*(code *)PTR_BUF_strlcpy_006a6f64)(buf_16723,iVar22,0x400);
                            (*(code *)PTR_BUF_strlcat_006a6f68)(buf_16723,"\n",0x400);
                            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar14,"%s\n",iVar22)
                            ;
LAB_00426e34:
                            if (buf_16723[0] == '\0') goto LAB_00426a74;
                            if (buf_16723[0] == '\n') goto LAB_00426f74;
                            if ((buf_16723[0] == '.') && (buf_16723[1] == '\n')) goto LAB_00426c1c;
                          }
                          pcStack_55c = "";
                          iVar21 = (*(code *)PTR_strlen_006a9a24)(buf_16723);
                          if ((&DAT_006a9c0f)[iVar21] != '\n') goto LAB_00426aac;
                          (&DAT_006a9c0f)[iVar21] = '\0';
                          iVar21 = req_check_len(iVar21 + -1,pcVar16,uVar19);
                          if (iVar21 != 0) goto LAB_00426ee4;
                          if ((batch != 0) || (iVar22 != 0)) goto LAB_00426a74;
LAB_00426ea4:
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar13,"%s [%s]:",pcStack_580,pcVar28);
                        } while( true );
                      }
                      uVar19 = *(undefined4 *)(iVar21 + 4);
LAB_00426928:
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar13,"Name \'%s\' too long\n",uVar19);
                      goto LAB_00425214;
                    }
                  }
                  goto LAB_00425d60;
                }
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar13,"No template, please set one up.\n");
              }
              else {
                iVar21 = build_subject(piVar38,pcStack_580,iStack_594);
                if (iVar21 != 0) {
LAB_00425d60:
                  iVar20 = (*(code *)PTR_X509_REQ_set_pubkey_006a6f30)(piVar38,iVar20);
                  pcVar36 = pcVar39;
                  if (iVar20 != 0) {
                    if ((bVar4) &&
                       (iVar20 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*piVar38 + 0x18)),
                       iVar20 == 0)) {
                      (*(code *)PTR_sk_free_006a6e80)(*(undefined4 *)(*piVar38 + 0x18));
                      *(undefined4 *)(*piVar38 + 0x18) = 0;
                    }
                    if (bVar5) {
                      pcStack_580 = (char *)0x0;
                      goto LAB_004255cc;
                    }
                    (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_50c,0,0,piVar38,0,0);
                    (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_50c,req_conf);
                    if ((pcStack_588 == (char *)0x0) ||
                       (iVar20 = (*(code *)PTR_X509V3_EXT_REQ_add_nconf_006a6f34)
                                           (req_conf,auStack_50c,pcStack_588,piVar38), iVar20 != 0))
                    {
                      iVar20 = do_X509_REQ_sign(*(undefined4 *)puVar13,piVar38,iStack_524,iStack_564
                                                ,puStack_5b8);
                      if (iVar20 != 0) goto LAB_00425688;
                      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar13,"Error Loading extension section %s\n",
                                 pcStack_588);
                    }
                    goto LAB_00425e60;
                  }
                }
              }
            }
          }
        }
        goto LAB_00425214;
      }
LAB_00425e60:
      iVar20 = 0;
      piVar33 = (int *)0x0;
      goto LAB_004245cc;
    }
    if (pcStack_55c == (char *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar17,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
    }
    else {
      iVar20 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar17,0x6c,3,pcStack_55c);
      pcVar36 = pcStack_55c;
      if (iVar20 < 1) {
LAB_0042633c:
        iVar20 = 0;
        (*(code *)PTR_perror_006a9a80)(pcVar36);
        piVar38 = (int *)0x0;
        piVar33 = (int *)0x0;
        goto LAB_004245cc;
      }
    }
    if (piVar38 == (int *)0x1) {
      piVar38 = (int *)(*(code *)PTR_d2i_X509_REQ_bio_006a6f80)(iVar17,0);
    }
    else {
      if (piVar38 != (int *)0x3) {
        iVar20 = 0;
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"bad input format specified for X509 request\n");
        piVar33 = (int *)0x0;
        goto LAB_004245cc;
      }
      piVar38 = (int *)(*(code *)PTR_PEM_read_bio_X509_REQ_006a6ee4)(iVar17,0,0,0);
    }
    if (piVar38 == (int *)0x0) {
      iVar20 = 0;
      piVar33 = (int *)0x0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"unable to load X509 request\n");
      goto LAB_004245cc;
    }
    if (bVar5) {
      if (iStack_524 == 0) goto LAB_00425634;
LAB_004255cc:
      piVar33 = (int *)(*(code *)PTR_X509_new_006a6ee8)();
      if ((piVar33 != (int *)0x0) &&
         ((pcStack_58c == (char *)0x0 ||
          (iVar20 = (*(code *)PTR_X509_set_version_006a6eec)(piVar33,2), iVar20 != 0)))) {
        if (iStack_5b4 == 0) {
          uVar19 = (*(code *)PTR_X509_get_serialNumber_006a6f9c)(piVar33);
          iVar20 = (*(code *)PTR_rand_serial_006a6fa0)(0,uVar19);
          if (iVar20 != 0) {
            iVar20 = *piVar38;
            goto LAB_00427178;
          }
        }
        else {
          iVar20 = (*(code *)PTR_X509_set_serialNumber_006a6f84)(piVar33,iStack_5b4);
          if (iVar20 != 0) {
            iVar20 = *piVar38;
LAB_00427178:
            iVar20 = (*(code *)PTR_X509_set_issuer_name_006a6f88)
                               (piVar33,*(undefined4 *)(iVar20 + 0x10));
            if ((((iVar20 != 0) &&
                 (iVar20 = (*(code *)PTR_X509_gmtime_adj_006a6f8c)
                                     (**(undefined4 **)(*piVar33 + 0x10),0), iVar20 != 0)) &&
                (iVar20 = (*(code *)PTR_X509_time_adj_ex_006a6f90)
                                    (*(undefined4 *)(*(int *)(*piVar33 + 0x10) + 4),iStack_544,0,0),
                iVar20 != 0)) &&
               (((iVar20 = (*(code *)PTR_X509_set_subject_name_006a6f94)
                                     (piVar33,*(undefined4 *)(*piVar38 + 0x10)), iVar20 != 0 &&
                 (iVar20 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(piVar38), iVar20 != 0)) &&
                (iVar21 = (*(code *)PTR_X509_set_pubkey_006a6f98)(piVar33,iVar20), iVar21 != 0)))) {
              (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar20);
              (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_50c,piVar33,piVar33,0,0,0);
              (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_50c,req_conf);
              if ((pcStack_58c == (char *)0x0) ||
                 (iVar20 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                     (req_conf,auStack_50c,pcStack_58c,piVar33), iVar20 != 0)) {
                puVar14 = PTR_bio_err_006a6e3c;
                iVar20 = do_X509_sign(*(undefined4 *)puVar13,piVar33,iStack_524,iStack_564,
                                      puStack_5b8);
                if (iVar20 != 0) {
                  if (pcStack_580 == (char *)0x0) goto LAB_004256e4;
                  iVar20 = 0;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar14,"Cannot modifiy certificate subject\n");
                  goto LAB_004245cc;
                }
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar14);
              }
              else {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar13,"Error Loading extension section %s\n",pcStack_58c
                          );
              }
            }
          }
        }
      }
LAB_00425604:
      iVar20 = 0;
      goto LAB_004245cc;
    }
    if (pcStack_580 != (char *)0x0) {
      if (pcStack_57c == (char *)0x0) {
        iVar20 = build_subject(piVar38,pcStack_580,iStack_594);
        if (iVar20 == 0) goto LAB_00426fc8;
        *(undefined4 *)(*piVar38 + 8) = 1;
      }
      else {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"Modifying Request\'s Subject\n");
        (*(code *)PTR_print_name_006a6f04)
                  (*(undefined4 *)puVar13,"old subject=",*(undefined4 *)(*piVar38 + 0x10),uStack_530
                  );
        iVar20 = build_subject(piVar38,pcStack_580,iStack_594,pcStack_558);
        puVar14 = PTR_print_name_006a6f04;
        if (iVar20 == 0) {
LAB_00426fc8:
          iVar20 = 0;
          piVar33 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"ERROR: cannot modify subject\n");
          goto LAB_004245cc;
        }
        iVar20 = *piVar38;
        uVar19 = *(undefined4 *)PTR_bio_err_006a6e3c;
        *(undefined4 *)(iVar20 + 8) = 1;
        (*(code *)puVar14)(uVar19,"new subject=",*(undefined4 *)(iVar20 + 0x10),uStack_530);
      }
    }
LAB_00425688:
    piVar33 = (int *)0x0;
    if (bVar6) {
      if (iStack_524 == 0) {
        iStack_524 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(piVar38);
        if (iStack_524 == 0) goto LAB_00425e60;
        iVar20 = (*(code *)PTR_X509_REQ_verify_006a6ef0)(piVar38,iStack_524);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iStack_524);
        iStack_524 = 0;
      }
      else {
        iVar20 = (*(code *)PTR_X509_REQ_verify_006a6ef0)(piVar38);
      }
      if (iVar20 < 0) goto LAB_00425e60;
      if (iVar20 == 0) {
        piVar33 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
      }
      else {
        piVar33 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"verify OK\n");
      }
    }
LAB_004256e4:
    if ((((!bVar7) || (bVar8)) || (bVar9)) || ((bVar10 || (bVar11)))) {
      if (pcStack_578 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
      }
      else {
        if ((pcStack_574 == (char *)0x0) ||
           (iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcStack_578,pcStack_574), iVar20 != 0)) {
          uVar19 = 5;
        }
        else {
          uVar19 = 9;
        }
        iVar20 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6c,uVar19,pcStack_578);
        if (iVar20 == 0) {
          iVar20 = 0;
          (*(code *)PTR_perror_006a9a80)(pcStack_578);
          goto LAB_004245cc;
        }
      }
      if (bVar11) {
        iVar20 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(piVar38);
        if (iVar20 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"Error getting public key\n");
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
          goto LAB_004245cc;
        }
        (*(code *)PTR_PEM_write_bio_PUBKEY_006a6f28)(iVar18,iVar20);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar20);
      }
      if (bVar8) {
        if (bVar5) {
          (*(code *)PTR_X509_print_ex_006a6efc)(iVar18,piVar33,uStack_530,uStack_52c);
          if (bVar10) goto LAB_004257b4;
          if (!bVar9) goto LAB_00425884;
LAB_004257ec:
          iVar20 = (*(code *)PTR_X509_get_pubkey_006a6f08)(piVar33);
        }
        else {
          (*(code *)PTR_X509_REQ_print_ex_006a6ef8)(iVar18,piVar38,uStack_530,uStack_52c);
          if (bVar10) {
LAB_00425a34:
            (*(code *)PTR_print_name_006a6f04)
                      (iVar18,"subject=",*(undefined4 *)(*piVar38 + 0x10),uStack_530);
          }
          if (!bVar9) goto LAB_00425884;
LAB_00425a64:
          iVar20 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(piVar38);
        }
        puVar14 = PTR_stdout_006a99c8;
        if (iVar20 == 0) {
          (*(code *)PTR_fwrite_006a9a74)
                    ("Modulus=unavailable\n",1,0x14,*(undefined4 *)PTR_stdout_006a99c8);
          goto LAB_004245cc;
        }
        (*(code *)PTR_fwrite_006a9a74)("Modulus=",1,8,*(undefined4 *)PTR_stdout_006a99c8);
        iVar21 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(iVar20);
        if (iVar21 == 6) {
          (*(code *)PTR_BN_print_006a6f24)(iVar18,*(undefined4 *)(*(int *)(iVar20 + 0x14) + 0x10));
        }
        else {
          (*(code *)PTR_fwrite_006a9a74)("Wrong Algorithm type",1,0x14,*(undefined4 *)puVar14);
        }
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar20);
        (*(code *)PTR_fputc_006a99a4)(10,*(undefined4 *)puVar14);
      }
      else if (bVar10) {
        if (!bVar5) goto LAB_00425a34;
LAB_004257b4:
        uVar19 = (*(code *)PTR_X509_get_subject_name_006a6f00)(piVar33);
        (*(code *)PTR_print_name_006a6f04)(iVar18,"subject=",uVar19,uStack_530);
        if (bVar9) goto LAB_004257ec;
      }
      else if (bVar9) {
        if (bVar5) goto LAB_004257ec;
        goto LAB_00425a64;
      }
LAB_00425884:
      if (!bVar7) {
        if (bVar5) {
          if (piVar33 != (int *)0x0) {
            if (pcVar39 == (char *)0x1) {
              iVar20 = (*(code *)PTR_i2d_X509_bio_006a6f1c)(iVar18,piVar33);
            }
            else {
              if (pcVar39 != (char *)0x3) goto LAB_0042590c;
              iVar20 = (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar18,piVar33);
            }
            if (iVar20 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar13,"unable to write X509 certificate\n");
              goto LAB_00425604;
            }
          }
        }
        else {
          if (pcVar39 == (char *)0x1) {
            iVar20 = (*(code *)PTR_i2d_X509_REQ_bio_006a6f10)(iVar18,piVar38);
          }
          else {
            if (pcVar39 != (char *)0x3) {
LAB_0042590c:
              iVar20 = 0;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar13,"bad output format specified for outfile\n");
              goto LAB_004245cc;
            }
            if (bVar12) {
              iVar20 = (*(code *)PTR_PEM_write_bio_X509_REQ_NEW_006a6f18)(iVar18,piVar38);
            }
            else {
              iVar20 = (*(code *)PTR_PEM_write_bio_X509_REQ_006a6f14)(iVar18,piVar38);
            }
          }
          if (iVar20 == 0) goto LAB_004258dc;
        }
      }
    }
    iVar20 = 0;
    uVar37 = 0;
  } while( true );
LAB_00426a40:
  iVar24 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a6f78)
                     (pcStack_598,iVar25,iStack_594,acStack_48d + 1,0xffffffff,0xffffffff,pcVar36);
  if (iVar24 == 0) goto LAB_00426a74;
  goto LAB_00426478;
LAB_00426aac:
  pcStack_55c = "";
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"weird input :-(\n");
  goto LAB_00425214;
LAB_00426ee4:
  iVar21 = (*(code *)PTR_X509_REQ_add1_attr_by_NID_006a6f7c)
                     (piVar38,pcVar36,iStack_594,buf_16723,0xffffffff);
  if (iVar21 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"Error adding attribute\n");
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
    goto LAB_00425214;
  }
LAB_00426c1c:
  iStack_5ac = iStack_5ac + 1;
  goto LAB_00426bc4;
LAB_00426a74:
  pcStack_55c = "";
LAB_00425214:
  if ((bVar4) &&
     (iVar20 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*piVar38 + 0x18)), iVar20 == 0)) {
    (*(code *)PTR_sk_free_006a6e80)(*(undefined4 *)(*piVar38 + 0x18));
    *(undefined4 *)(*piVar38 + 0x18) = 0;
  }
  iVar20 = 0;
  piVar33 = (int *)0x0;
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"problems making Certificate Request\n")
  ;
  pcVar39 = pcVar36;
  goto LAB_004245cc;
LAB_004258dc:
  iVar20 = 0;
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"unable to write X509 request\n");
  goto LAB_004245cc;
}

