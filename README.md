# Example NuGet package for a C++ static library

A public example of how to create and publish a NuGet package containing a native C++ static library.

NuGet was originally designed as a package management system for .NET dependencies
targeting the Common Language Runtime (CLR).  Most people think of it only in
that context.  But NuGet packages can also contain native libraries and
resources for pretty much any project using the MSBuild system (Visual Studio).

This example library is utterly trivial, it serves only as a placeholder to
demonstrate how to package the header files and binaries of a native library,
static or shared.

## The Pieces

A NuGet package is just a simple ZIP file that contains a few expected pieces.
When creating a .NET library intended for NuGet packaging, there is a lot of
helpful integration with the `csproj` file such as metadata, build settings,
and more.  The older `vcxproj` file does not support any of that, so we need
to create a couple extra files to bridge the gap.

This also means that PackageReference is not available for declaring dependencies
for the library.  If the library depends on other libraries, those must be
declared using `packages.config`.  (This also applies to SourceLink.)

### The `nuspec` File

The first thing we need is a `*.nuspec` file to define what the NuGet package
should contain.  This will hold the metadata for the package and declare what
contents will be packaged for distribution.  Each NuGet package must declare
what frameworks it targets (supports, works on).  For .NET libraries, this will
be a list of .NET releases.  For native code, the target framework is simply
"`native`".

Other metadata works just like in packages containing managed code.  You can
specify the NuGet package identifier (ID), version, description, license
information, tags, and so forth.

The `*.nuspec` file will also contain a list of files (artifacts) that will be
included in the distributable package.  This includes both source code copied
straight from the project and compiled artifacts produced by running a build.
A single NuGet package can offer multiple variations of its contents, so it may
require multiple builds to generate all of the artifacts needed to create the
NuGet package.  For example, offering both Debug and Release versions of the
library, and offering builds for multiple architectures.  The `nuspec` file
does not specify how any particular artifact is created or where it comes from,
only where to find it in the local filesystem relative to `nuspec` file itself.

### The MSBuild Files

The way that NuGet dependencies are integrated into the MSBuild system is by
providing MSBuild files that get included in the project using the dependency.
This includes an MSBuild `*.targets` file that declares any new build targets
needed for the dependency (the library), and a `*.props` file that declares any
new or overridden properties.  The `props` file in particular is crucial for a
native library, because that allows the NuGet package to specify additional
`include` directories (for finding the library's header files) and `lib`
directories and command-line parameters.

Since these files are MSBuild files, they support MSBuild properties and
conditionals, which is how a consuming application can select the correct
when a NuGet package offers multiple variants.  This logic is provided by the
dependency, so the consuming application does not need to be aware of the
details of how the correct variant is chosen.  (This also offers the
possibility of a poorly-written NuGet package breaking the build of a
consumer, so providers of NuGet packages must be diligent.)

One thing to be aware of is that these MSBuild files will be placed inside of
a subdirectory of `build` in the NuGet package based on the declared target
framework.  Therefore relative paths must account for this when referencing
other files in the package.  For example, adding the dependency's header files
to the include directories could look like this:

```
$(MSBuildThisFileDirectory)..\..\include;$(AdditionalIncludeDirectories)
```

The `*.props` file will be in the `build/native` directory of the NuGet package,
while the header files will be in `include`, so relative to the `props` file
the headers will be up two directories.

### Header Files

Traditionally header files are simply copied from the project into the NuGet
package, but there is no technical reason that header files could not be
generated or modified in a build.  The convention is that header files be placed
into an `include` directory in the root of the NuGet package, though again this
is not strictly required.

### Compiled Libraries

The convention from NuGet packages containing managed code is that variants for
different target frameworks are placed in the `lib/<framework>` directory.
Since the "framework" for native code is simply "`native`", that means compiled
binaries are placed in the `lib/native` directory.  The specific platform and
configuration for each binary variant is typically used as a subdirectory, so
the `*.lib` and `*.dll` files usually end up in `lib/native/x86/Release` and
similar locations.

PDB files and XMLDoc can be packaged with the compiled binaries.

### Additional Niceties

One very important part of making a good NuGet package is including enough
additional information so that users can actually understand how to make use of
your package.  Adding a README is crucial, and SourceLink and other information
can be the difference between being viewed as competent versus amateur.

#### README File

This one is trivial, but very important.  Include a `README.md` file in the
root of the NuGet package.  Specify that this file exists in the metadata of
the `nuspec` file.

#### SourceLink

This is best accomplished by adding the appropriate NuGet dependencies to the
project that will be packaged as your own NuGet package.  Look for the NuGet
packages named `Microsoft.SourceLink.*`, and select the correct one for whatever
source control system you are using.  Since this will be a development dependency,
it will not be transitively applied to any application consuming your NuGet
package.
