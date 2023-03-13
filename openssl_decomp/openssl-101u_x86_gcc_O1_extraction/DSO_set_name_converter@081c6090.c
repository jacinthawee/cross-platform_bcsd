
int DSO_set_name_converter(DSO *dso,DSO_NAME_CONVERTER_FUNC cb,DSO_NAME_CONVERTER_FUNC *oldcb)

{
  int iVar1;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x7a,0x43,"dso_lib.c",0x145);
    iVar1 = 0;
  }
  else {
    if (oldcb != (DSO_NAME_CONVERTER_FUNC *)0x0) {
      *oldcb = dso->name_converter;
    }
    dso->name_converter = cb;
    iVar1 = 1;
  }
  return iVar1;
}

