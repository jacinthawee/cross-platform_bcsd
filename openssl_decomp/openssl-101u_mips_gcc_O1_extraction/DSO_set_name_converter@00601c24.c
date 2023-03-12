
int DSO_set_name_converter(DSO *dso,DSO_NAME_CONVERTER_FUNC cb,DSO_NAME_CONVERTER_FUNC *oldcb)

{
  if (dso != (DSO *)0x0) {
    if (oldcb != (DSO_NAME_CONVERTER_FUNC *)0x0) {
      *oldcb = dso->name_converter;
    }
    dso->name_converter = cb;
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x7a,0x43,"dso_lib.c",0x145);
  return 0;
}

