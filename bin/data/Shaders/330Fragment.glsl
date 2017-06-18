#version 330 core

in vec4 fragColor;
in vec2 TexCoord;

uniform int hasTexture;
uniform sampler2D Texture;

void main()
{
   if (hasTexture == 1)
   {
      gl_FragColor = texture2D(Texture, TexCoord) * fragColor;
   }
   else
   {
      gl_FragColor = fragColor;
   }
}
