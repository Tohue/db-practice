#!/bin/bash
xsltproc /usr/share/xml/docbook/stylesheet/docbook-xsl/fo/docbook.xsl test.xml > book.fo
fop -fo book.fo -pdf book.pdf
