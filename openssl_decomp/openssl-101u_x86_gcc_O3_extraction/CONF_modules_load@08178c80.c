
int CONF_modules_load(CONF *cnf,char *appname,ulong flags)

{
  char *__s;
  bool bVar1;
  char *pcVar2;
  _STACK *p_Var3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  size_t __n;
  int iVar7;
  DSO *pDVar8;
  DSO *pDVar9;
  DSO *pDVar10;
  DSO **data;
  DSO *pDVar11;
  void **data_00;
  int in_GS_OFFSET;
  int local_60;
  char local_2d [13];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cnf != (CONF *)0x0) {
    if (appname == (char *)0x0) {
LAB_081790cd:
      pcVar2 = NCONF_get_string(cnf,(char *)0x0,"openssl_conf");
      if (pcVar2 == (char *)0x0) {
LAB_0817908b:
        ERR_clear_error();
        goto LAB_08179090;
      }
    }
    else {
      pcVar2 = NCONF_get_string(cnf,(char *)0x0,appname);
      if (pcVar2 == (char *)0x0) {
        if ((flags & 0x20) != 0) goto LAB_081790cd;
        goto LAB_0817908b;
      }
    }
    p_Var3 = (_STACK *)NCONF_get_section(cnf,pcVar2);
    if (p_Var3 == (_STACK *)0x0) {
      iVar4 = 0;
      goto LAB_08179095;
    }
    for (local_60 = 0; iVar4 = sk_num(p_Var3), local_60 < iVar4; local_60 = local_60 + 1) {
      pvVar5 = sk_value(p_Var3,local_60);
      pcVar2 = *(char **)((int)pvVar5 + 8);
      __s = *(char **)((int)pvVar5 + 4);
      pcVar6 = strrchr(__s,0x2e);
      if (pcVar6 == (char *)0x0) {
        __n = strlen(__s);
      }
      else {
        __n = (int)pcVar6 - (int)__s;
      }
      for (iVar4 = 0; iVar7 = sk_num(supported_modules), iVar4 < iVar7; iVar4 = iVar4 + 1) {
        data = (DSO **)sk_value(supported_modules,iVar4);
        iVar7 = strncmp((char *)data[1],__s,__n);
        if (iVar7 == 0) goto LAB_08178eb0;
      }
      if ((flags & 8) == 0) {
        pcVar6 = NCONF_get_string(cnf,pcVar2,"path");
        if (pcVar6 == (char *)0x0) {
          ERR_clear_error();
          pcVar6 = __s;
        }
        pDVar8 = DSO_load((DSO *)0x0,pcVar6,(DSO_METHOD *)0x0,0);
        if (pDVar8 == (DSO *)0x0) {
          iVar4 = 0x6e;
LAB_0817910b:
          ERR_put_error(0xe,0x75,iVar4,"conf_mod.c",0x10f);
          ERR_add_error_data(4,"module=",__s,", path=",pcVar6);
          goto LAB_08178da9;
        }
        pDVar9 = (DSO *)DSO_bind_func(pDVar8,"OPENSSL_init");
        if (pDVar9 == (DSO *)0x0) {
          iVar4 = 0x70;
LAB_081790ff:
          DSO_free(pDVar8);
          goto LAB_0817910b;
        }
        pDVar10 = (DSO *)DSO_bind_func(pDVar8,"OPENSSL_finish");
        if (((supported_modules == (_STACK *)0x0) &&
            (supported_modules = sk_new_null(), supported_modules == (_STACK *)0x0)) ||
           (data = (DSO **)CRYPTO_malloc(0x18,"conf_mod.c",0x11d), data == (DSO **)0x0)) {
LAB_081790fd:
          iVar4 = 0;
          goto LAB_081790ff;
        }
        *data = pDVar8;
        pDVar11 = (DSO *)BUF_strdup(__s);
        data[1] = pDVar11;
        data[4] = (DSO *)0x0;
        data[2] = pDVar9;
        data[3] = pDVar10;
        iVar4 = sk_push(supported_modules,data);
        if (iVar4 == 0) {
          CRYPTO_free(data);
          goto LAB_081790fd;
        }
LAB_08178eb0:
        data_00 = (void **)CRYPTO_malloc(0x14,"conf_mod.c",0x154);
        if (data_00 == (void **)0x0) {
LAB_08178fbc:
          if ((flags & 4) != 0) goto LAB_08178db5;
          ERR_put_error(0xe,0x76,0x6d,"conf_mod.c",0xdf);
          BIO_snprintf(local_2d,0xd,"%-8d",0xffffffff);
          ERR_add_error_data(6,"module=",__s,", value=",pcVar2,", retcode=",local_2d);
          if ((flags & 1) != 0) goto LAB_08178dc1;
          goto LAB_08179028;
        }
        *data_00 = data;
        pcVar6 = BUF_strdup(__s);
        data_00[1] = pcVar6;
        pcVar6 = BUF_strdup(pcVar2);
        pvVar5 = data_00[1];
        data_00[2] = pcVar6;
        data_00[4] = (void *)0x0;
        bVar1 = pvVar5 == (void *)0x0 || pcVar6 == (char *)0x0;
        if (bVar1) {
LAB_08178f8d:
          if (pvVar5 != (void *)0x0) {
            CRYPTO_free(pvVar5);
          }
          if (data_00[2] != (void *)0x0) {
            CRYPTO_free(data_00[2]);
          }
          CRYPTO_free(data_00);
          goto LAB_08178fbc;
        }
        if (data[2] != (DSO *)0x0) {
          iVar4 = (*(code *)data[2])(data_00,cnf);
          if (0 < iVar4) {
            bVar1 = true;
            goto LAB_08178f2c;
          }
          pDVar8 = data[3];
          if (pDVar8 == (DSO *)0x0) goto LAB_0817907e;
LAB_08178f81:
          (*(code *)pDVar8)(data_00);
          pvVar5 = data_00[1];
          goto LAB_08178f8d;
        }
LAB_08178f2c:
        if ((initialized_modules == (_STACK *)0x0) &&
           (initialized_modules = sk_new_null(), initialized_modules == (_STACK *)0x0)) {
          iVar4 = 0x16c;
LAB_08178f5b:
          ERR_put_error(0xe,0x73,0x41,"conf_mod.c",iVar4);
          pDVar8 = data[3];
          if ((pDVar8 == (DSO *)0x0) || (!bVar1)) {
LAB_0817907e:
            pvVar5 = data_00[1];
            goto LAB_08178f8d;
          }
          goto LAB_08178f81;
        }
        iVar4 = sk_push(initialized_modules,data_00);
        if (iVar4 == 0) {
          iVar4 = 0x172;
          goto LAB_08178f5b;
        }
        data[4] = (DSO *)((int)&data[4]->meth + 1);
      }
      else {
LAB_08178da9:
        if ((flags & 4) == 0) {
          ERR_put_error(0xe,0x76,0x71,"conf_mod.c",0xd4);
          ERR_add_error_data(2,"module=",__s);
        }
LAB_08178db5:
        if ((flags & 1) == 0) {
LAB_08179028:
          iVar4 = -1;
          goto LAB_08179095;
        }
      }
LAB_08178dc1:
    }
  }
LAB_08179090:
  iVar4 = 1;
LAB_08179095:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

