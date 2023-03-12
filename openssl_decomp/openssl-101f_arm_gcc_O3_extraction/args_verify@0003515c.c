
undefined4
args_verify(int *param_1,int *param_2,int *param_3,BIO *param_4,X509_VERIFY_PARAM **param_5)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  X509_PURPOSE *pXVar3;
  X509_VERIFY_PARAM *param;
  char **ppcVar4;
  char **ppcVar5;
  char *__s1;
  long depth;
  ASN1_OBJECT *policy;
  ASN1_OBJECT *flags;
  ASN1_OBJECT *local_2c [2];
  
  ppcVar5 = (char **)*param_1;
  __s1 = *ppcVar5;
  policy = (ASN1_OBJECT *)ppcVar5[1];
  iVar1 = strcmp(__s1,"-policy");
  if (iVar1 == 0) {
    if (policy == (ASN1_OBJECT *)0x0) {
      iVar1 = 1;
      *param_3 = 1;
      ppcVar4 = ppcVar5;
    }
    else {
      pAVar2 = OBJ_txt2obj((char *)policy,0);
      if (pAVar2 == (ASN1_OBJECT *)0x0) {
        BIO_printf(param_4,"Invalid Policy \"%s\"\n",policy);
        ppcVar4 = (char **)*param_1;
        iVar1 = 1;
        *param_3 = 1;
        policy = pAVar2;
      }
      else {
        iVar1 = *param_3;
        ppcVar4 = (char **)*param_1;
        policy = pAVar2;
      }
    }
    depth = -1;
    *param_1 = (int)(ppcVar4 + 1);
    local_2c[0] = (ASN1_OBJECT *)0x0;
    pAVar2 = (ASN1_OBJECT *)0x0;
    flags = (ASN1_OBJECT *)0x0;
LAB_000351ac:
    if (iVar1 == 0) goto LAB_00035226;
LAB_000351b0:
    if (*param_5 != (X509_VERIFY_PARAM *)0x0) {
      X509_VERIFY_PARAM_free(*param_5);
    }
    *param_5 = (X509_VERIFY_PARAM *)0x0;
  }
  else {
    pAVar2 = (ASN1_OBJECT *)strcmp(__s1,"-purpose");
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      iVar1 = strcmp(__s1,"-verify_depth");
      if (iVar1 == 0) {
        if (policy == (ASN1_OBJECT *)0x0) {
          iVar1 = 1;
          *param_3 = 1;
          depth = -1;
          ppcVar4 = ppcVar5;
        }
        else {
          depth = strtol((char *)policy,(char **)0x0,10);
          if (depth < 0) {
            BIO_printf(param_4,"invalid depth\n");
            ppcVar4 = (char **)*param_1;
            iVar1 = 1;
            *param_3 = 1;
          }
          else {
            iVar1 = *param_3;
            ppcVar4 = (char **)*param_1;
          }
        }
        policy = (ASN1_OBJECT *)0x0;
        *param_1 = (int)(ppcVar4 + 1);
        local_2c[0] = policy;
        pAVar2 = policy;
        flags = policy;
      }
      else {
        iVar1 = strcmp(__s1,"-attime");
        if (iVar1 == 0) {
          if (policy == (ASN1_OBJECT *)0x0) {
            iVar1 = 1;
            *param_3 = 1;
            ppcVar4 = ppcVar5;
            local_2c[0] = policy;
          }
          else {
            iVar1 = __isoc99_sscanf(policy,&DAT_00133224,local_2c);
            if (iVar1 == 1) {
              iVar1 = *param_3;
            }
            else {
              BIO_printf(bio_err,"Error parsing timestamp %s\n",policy);
              iVar1 = 1;
              *param_3 = 1;
            }
            ppcVar4 = (char **)*param_1;
          }
          flags = (ASN1_OBJECT *)0x0;
          *param_1 = (int)(ppcVar4 + 1);
          depth = -1;
          policy = (ASN1_OBJECT *)0x0;
          pAVar2 = (ASN1_OBJECT *)0x0;
        }
        else {
          policy = (ASN1_OBJECT *)strcmp(__s1,"-ignore_critical");
          if (policy == (ASN1_OBJECT *)0x0) {
            iVar1 = *param_3;
            depth = -1;
            flags = (ASN1_OBJECT *)&DAT_00000010;
            local_2c[0] = policy;
            pAVar2 = policy;
          }
          else {
            policy = (ASN1_OBJECT *)strcmp(__s1,"-issuer_checks");
            if (policy == (ASN1_OBJECT *)0x0) {
              iVar1 = *param_3;
              depth = -1;
              flags = (ASN1_OBJECT *)0x1;
              local_2c[0] = policy;
              pAVar2 = policy;
            }
            else {
              policy = (ASN1_OBJECT *)strcmp(__s1,"-crl_check");
              if (policy == (ASN1_OBJECT *)0x0) {
                iVar1 = *param_3;
                depth = -1;
                flags = (ASN1_OBJECT *)&DAT_00000004;
                local_2c[0] = policy;
                pAVar2 = policy;
              }
              else {
                policy = (ASN1_OBJECT *)strcmp(__s1,"-crl_check_all");
                if (policy == (ASN1_OBJECT *)0x0) {
                  iVar1 = *param_3;
                  depth = -1;
                  flags = (ASN1_OBJECT *)&DAT_0000000c;
                  local_2c[0] = policy;
                  pAVar2 = policy;
                }
                else {
                  policy = (ASN1_OBJECT *)strcmp(__s1,"-policy_check");
                  if (policy == (ASN1_OBJECT *)0x0) {
                    iVar1 = *param_3;
                    depth = -1;
                    flags = (ASN1_OBJECT *)0x80;
                    local_2c[0] = policy;
                    pAVar2 = policy;
                  }
                  else {
                    iVar1 = strcmp(__s1,"-explicit_policy");
                    if (iVar1 == 0) {
                      iVar1 = *param_3;
                      policy = (ASN1_OBJECT *)0x0;
                      depth = -1;
                      flags = (ASN1_OBJECT *)0x100;
                      local_2c[0] = (ASN1_OBJECT *)0x0;
                      pAVar2 = (ASN1_OBJECT *)0x0;
                    }
                    else {
                      policy = (ASN1_OBJECT *)strcmp(__s1,"-inhibit_any");
                      if (policy == (ASN1_OBJECT *)0x0) {
                        iVar1 = *param_3;
                        depth = -1;
                        flags = (ASN1_OBJECT *)0x200;
                        local_2c[0] = policy;
                        pAVar2 = policy;
                      }
                      else {
                        policy = (ASN1_OBJECT *)strcmp(__s1,"-inhibit_map");
                        if (policy == (ASN1_OBJECT *)0x0) {
                          iVar1 = *param_3;
                          depth = -1;
                          flags = (ASN1_OBJECT *)0x400;
                          local_2c[0] = policy;
                          pAVar2 = policy;
                        }
                        else {
                          policy = (ASN1_OBJECT *)strcmp(__s1,"-x509_strict");
                          if (policy == (ASN1_OBJECT *)0x0) {
                            iVar1 = *param_3;
                            depth = -1;
                            flags = (ASN1_OBJECT *)0x20;
                            local_2c[0] = policy;
                            pAVar2 = policy;
                          }
                          else {
                            policy = (ASN1_OBJECT *)strcmp(__s1,"-extended_crl");
                            if (policy == (ASN1_OBJECT *)0x0) {
                              iVar1 = *param_3;
                              depth = -1;
                              flags = (ASN1_OBJECT *)0x1000;
                              local_2c[0] = policy;
                              pAVar2 = policy;
                            }
                            else {
                              policy = (ASN1_OBJECT *)strcmp(__s1,"-use_deltas");
                              if (policy == (ASN1_OBJECT *)0x0) {
                                iVar1 = *param_3;
                                depth = -1;
                                flags = (ASN1_OBJECT *)0x2000;
                                local_2c[0] = policy;
                                pAVar2 = policy;
                              }
                              else {
                                policy = (ASN1_OBJECT *)strcmp(__s1,"-policy_print");
                                if (policy == (ASN1_OBJECT *)0x0) {
                                  iVar1 = *param_3;
                                  depth = -1;
                                  flags = (ASN1_OBJECT *)0x800;
                                  local_2c[0] = policy;
                                  pAVar2 = policy;
                                }
                                else {
                                  policy = (ASN1_OBJECT *)strcmp(__s1,"-check_ss_sig");
                                  if (policy != (ASN1_OBJECT *)0x0) {
                                    return 0;
                                  }
                                  iVar1 = *param_3;
                                  depth = -1;
                                  flags = (ASN1_OBJECT *)0x4000;
                                  local_2c[0] = policy;
                                  pAVar2 = policy;
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
      goto LAB_000351ac;
    }
    if (policy == (ASN1_OBJECT *)0x0) {
      iVar1 = 1;
      *param_3 = 1;
      ppcVar4 = ppcVar5;
      pAVar2 = policy;
    }
    else {
      iVar1 = X509_PURPOSE_get_by_sname((char *)policy);
      if (iVar1 < 0) {
        BIO_printf(param_4,"unrecognized purpose\n");
        iVar1 = 1;
        *param_3 = 1;
        ppcVar4 = (char **)*param_1;
      }
      else {
        pXVar3 = X509_PURPOSE_get0(iVar1);
        pAVar2 = (ASN1_OBJECT *)X509_PURPOSE_get_id(pXVar3);
        iVar1 = *param_3;
        ppcVar4 = (char **)*param_1;
      }
    }
    local_2c[0] = (ASN1_OBJECT *)0x0;
    flags = (ASN1_OBJECT *)0x0;
    *param_1 = (int)(ppcVar4 + 1);
    depth = -1;
    policy = (ASN1_OBJECT *)0x0;
    if (iVar1 != 0) goto LAB_000351b0;
LAB_00035226:
    param = *param_5;
    if (param == (X509_VERIFY_PARAM *)0x0) {
      param = X509_VERIFY_PARAM_new();
      *param_5 = param;
      if (param == (X509_VERIFY_PARAM *)0x0) {
        *param_3 = 1;
        goto LAB_000351c0;
      }
    }
    if (policy != (ASN1_OBJECT *)0x0) {
      X509_VERIFY_PARAM_add0_policy(param,policy);
    }
    if (flags != (ASN1_OBJECT *)0x0) {
      X509_VERIFY_PARAM_set_flags(*param_5,(ulong)flags);
    }
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      X509_VERIFY_PARAM_set_purpose(*param_5,(int)pAVar2);
    }
    if (-1 < depth) {
      X509_VERIFY_PARAM_set_depth(*param_5,depth);
    }
    if (local_2c[0] != (ASN1_OBJECT *)0x0) {
      X509_VERIFY_PARAM_set_time(*param_5,(time_t)local_2c[0]);
      iVar1 = *param_1 + 4;
      *param_1 = iVar1;
      goto joined_r0x000351c8;
    }
  }
LAB_000351c0:
  iVar1 = *param_1 + 4;
  *param_1 = iVar1;
joined_r0x000351c8:
  if (param_2 != (int *)0x0) {
    *param_2 = *param_2 - (iVar1 - (int)ppcVar5 >> 2);
    return 1;
  }
  return 1;
}

