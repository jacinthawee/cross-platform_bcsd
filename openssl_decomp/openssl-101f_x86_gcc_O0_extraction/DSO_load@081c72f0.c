
DSO * DSO_load(DSO *dso,char *filename,DSO_METHOD *meth,int flags)

{
  _func_3765 *p_Var1;
  bool bVar2;
  int iVar3;
  
  bVar2 = false;
  if (dso == (DSO *)0x0) {
    dso = DSO_new_method(meth);
    if (dso == (DSO *)0x0) {
      ERR_put_error(0x25,0x70,0x41,"dso_lib.c",0xcc);
      return (DSO *)0x0;
    }
    bVar2 = true;
    dso->flags = flags;
  }
  if (dso->filename != (char *)0x0) {
    ERR_put_error(0x25,0x70,0x6e,"dso_lib.c",0xdc);
    goto LAB_081c7323;
  }
  if (filename != (char *)0x0) {
    iVar3 = DSO_set_filename(dso,filename);
    if (iVar3 == 0) {
      ERR_put_error(0x25,0x70,0x70,"dso_lib.c",0xe4);
      goto LAB_081c7323;
    }
    if (dso->filename != (char *)0x0) {
      p_Var1 = dso->meth->dso_load;
      if (p_Var1 == (_func_3765 *)0x0) {
        ERR_put_error(0x25,0x70,0x6c,"dso_lib.c",0xef);
      }
      else {
        iVar3 = (*p_Var1)(dso);
        if (iVar3 != 0) {
          return dso;
        }
        ERR_put_error(0x25,0x70,0x67,"dso_lib.c",0xf4);
      }
      goto LAB_081c7323;
    }
  }
  ERR_put_error(0x25,0x70,0x6f,"dso_lib.c",0xea);
LAB_081c7323:
  if (!bVar2) {
    return (DSO *)0x0;
  }
  DSO_free(dso);
  return (DSO *)0x0;
}

