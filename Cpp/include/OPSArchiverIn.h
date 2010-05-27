/**
 *
 * Copyright (C) 2006-2009 Anton Gravestam.
 *
 * This notice apply to all source files, *.cpp, *.h, *.java, and *.cs in this directory
 * and all its subdirectories if nothing else is explicitly stated within the source file itself.
 *
 * This file is part of OPS (Open Publish Subscribe).
 *
 * OPS (Open Publish Subscribe) is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * OPS (Open Publish Subscribe) is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with OPS (Open Publish Subscribe).  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ops_OPSArchiverInH
#define ops_OPSArchiverInH

#include "ByteBuffer.h"
#include "OPSObjectFactory.h"
#include "Serializable.h"
#include "ArchiverInOut.h"
#include <vector>

namespace ops
{

    class OPSArchiverIn : public ArchiverInOut
    {
    public:

        OPSArchiverIn(ByteBuffer* _buf)
        {
            buf = _buf;
            factory = OPSObjectFactory::getInstance();
        }

        OPSArchiverIn(ByteBuffer* _buf, OPSObjectFactory* factory)
        {
            buf = _buf;
            this->factory = factory;
        }

        ~OPSArchiverIn()
        {
        }

        void inout(const std::string& name, bool& value)
        {
            value = buf->ReadChar() > 0;
        }

        void inout(const std::string& name, char& value)
        {
            value = buf->ReadChar();
        }

        void inout(const std::string& name, int& value)
        {
            value = buf->ReadInt();
        }

        void inout(const std::string& name, __int16& value)
        {
            //Not implemented
            value = buf->ReadShort();
        }

        void inout(const std::string& name, __int64& value)
        {
            value = buf->ReadLong();
        }

        void inout(const std::string& name, float& value)
        {
            value = buf->ReadFloat();
        }

        void inout(const std::string& name, double& value)
        {
            value = buf->ReadDouble();
        }

        void inout(const std::string& name, std::string& value)
        {
            value = buf->ReadString();
        }

        void inout(const std::string& name, Serializable& value)
        {
            std::string types = buf->ReadString();
            value.serialize(this);
        }

        Serializable* inout(const std::string& name, Serializable* value, int element)
        {
            std::string types = buf->ReadString();
            Serializable* newSer = factory->create(types);
            if (newSer != NULL)
            {
                newSer->serialize(this);
            }

            return newSer;
        }

        Serializable* inout(const std::string& name, Serializable* value)
        {

            if (value != NULL)//Either we do this or we initiialize object to NULL in generated code.
            {
                delete value;
            }
            std::string types = buf->ReadString();
            Serializable* newSer = factory->create(types);
            if (newSer != NULL)
            {
                //Do this to preserve type information even if slicing has occured.
                ((OPSObject*) newSer)->typesString = types;

                newSer->serialize(this);
            }

            return newSer;
        }

        void inout(const std::string& name, std::vector<bool>& value)
        {
            buf->ReadBooleans(value);
        }

        void inout(const std::string& name, std::vector<char>& value)
        {
            buf->ReadBytes(value);
        }

        void inout(const std::string& name, std::vector<int>& value)
        {
            buf->ReadInts(value);
        }

        void inout(const std::string& name, std::vector<__int16>& value)
        {
            //Not implemented
            //return value;
        }

        void inout(const std::string& name, std::vector<__int64>& value)
        {
            buf->ReadLongs(value);
        }

        void inout(const std::string& name, std::vector<float>& value)
        {
            buf->ReadFloats(value);
        }

        void inout(const std::string& name, std::vector<double>& value)
        {
            buf->ReadDoubles(value);
        }

        void inout(const std::string& name, std::vector<std::string>& value)
        {
            buf->ReadStrings(value);
        }

        int beginList(const std::string& name, int size)
        {
            return buf->ReadInt();
        }

        void endList(const std::string& name)
        {
            //Nothing to do in this implementation
        }

        /*template <class SerializableTypeVector> SerializableTypeVector archiveSerializables(ArchiverInOut* archive, SerializableTypeVector vec)
        {
                int size = archive->inout("size", size);
                for(unsigned int i = 0; i < size; i++)
                {
                        vec[i] = archive->inout((Serializable*)NULL);
                }
                return vec;

        }*/


    private:
        ByteBuffer* buf;
        OPSObjectFactory* factory;
    };


}
#endif
