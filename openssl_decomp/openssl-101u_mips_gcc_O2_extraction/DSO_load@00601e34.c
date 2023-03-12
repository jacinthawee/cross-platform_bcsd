
DSO * DSO_load(DSO *dso,char *filename,DSO_METHOD *meth,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  _func_3765 *p_Var5;
  
  if (dso == (DSO *)0x0) {
    dso = DSO_new_method(meth);
    if (dso == (DSO *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x70,0x41,"dso_lib.c",0xc5);
      return (DSO *)0x0;
    }
    bVar1 = true;
    dso->flags = flags;
  }
  else {
    bVar1 = false;
  }
  if (dso->filename != (char *)0x0) {
    uVar4 = 0x6e;
    uVar2 = 0xd2;
    goto LAB_00601e78;
  }
  if (filename != (char *)0x0) {
    iVar3 = DSO_set_filename(dso,filename);
    if (iVar3 == 0) {
      uVar4 = 0x70;
      uVar2 = 0xdb;
      goto LAB_00601e78;
    }
    if (dso->filename != (char *)0x0) {
      p_Var5 = dso->meth->dso_load;
      uVar4 = 0x6c;
      if (p_Var5 == (_func_3765 *)0x0) {
        uVar2 = 0xe4;
      }
      else {
        iVar3 = (*p_Var5)(dso);
        if (iVar3 != 0) {
          return dso;
        }
        uVar4 = 0x67;
        uVar2 = 0xe8;
      }
      goto LAB_00601e78;
    }
  }
  uVar4 = 0x6f;
  uVar2 = 0xe0;
LAB_00601e78:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x70,uVar4,"dso_lib.c",uVar2);
  if (!bVar1) {
    return (DSO *)0x0;
  }
  DSO_free(dso);
  return (DSO *)0x0;
}

